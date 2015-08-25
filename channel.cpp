#include "channel.h"

#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QRegularExpression>

using namespace ThingSpeak;

const QString Channel::updatePathDefault = "/update";

Channel::Channel(ApiManager &manager, QString apiKey): manager(manager), apiKey(apiKey), updatePath(updatePathDefault)
{

};

bool Channel::checkFieldId(unsigned int fieldId) const
{
    if (fieldId > 0 && fieldId <= 8)
        return true;

    return false;
}

unsigned int Channel::parseFieldPostReply(QNetworkReply *reply) const
{
    unsigned int retVal;

    if (reply->error() == QNetworkReply::NoError)
    {
        QString retString = QString(reply->readAll());
        qDebug() << "HTTP post request success : " << retString;
        retVal = retString.toUInt();
    }

    else  {
        qDebug() << "HTTP post request failure : " << reply->errorString();
        retVal = kPostError;
    }

    return retVal;
}

QString buildFieldString(unsigned int fieldId)
{
    return QString("field%1").arg(fieldId);
}

unsigned int Channel::postField(unsigned int fieldId, const QString &fieldValue)
{
    if (!checkFieldId(fieldId))
        return kPostError;

    // Create query
    QUrlQuery query;
    query.addQueryItem("api_key", apiKey);
    query.addQueryItem(buildFieldString(fieldId), fieldValue);

    // Send request and parse the reply
    QNetworkReply *reply = manager.sendPostRequestSync(updatePath, query);
    unsigned int retVal = parseFieldPostReply(reply);
    delete reply;

    return retVal;
}



