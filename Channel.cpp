#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QRegularExpression>

#include "Channel.h"

using namespace ThingSpeak;

static const QString updatePathDefault = "/update";

Channel::Channel(ApiManager &manager, QString apiKey): manager(manager), apiKey(apiKey), updatePath(updatePathDefault)
{ };

bool Channel::checkFieldId(unsigned int fieldId) const
{
    if (fieldId > 0 && fieldId <= 8)
        return true;

    return false;
}

tsid_t Channel::postField(unsigned int fieldId, const QString &fieldValue)
{
    if (!checkFieldId(fieldId))
        return kInvalidId;

    // Create query
    QUrlQuery query;
    query.addQueryItem("api_key", apiKey);
    query.addQueryItem(QString("field%1").arg(fieldId), fieldValue);

    // Send request and parse the reply
    QNetworkReply *reply = manager.sendPostRequestSync(updatePath, query);
    tsid_t retVal = parseReplyForID(reply);
    delete reply;

    return retVal;
}



