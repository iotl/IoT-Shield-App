#include "ApiCommon.h"
#include <QString>

quint64 ThingSpeak::parseReplyForID(QNetworkReply *reply)
{
    unsigned int retVal;
    if (!reply)
        return kInvalidId;

    if (reply->error() == QNetworkReply::NoError) {
        QString retString = QString(reply->readAll());
        qDebug() << "HTTP request success : " << retString;
        retVal = retString.toUInt();
    }

    else  {
        qDebug() << "HTTP request failure : " << reply->errorString();
        retVal = kInvalidId;
    }

    return retVal;
}


QString ThingSpeak::parseReplyForString(QNetworkReply *reply)
{
    QString retString;
    if (!reply)
        return retString;

    if (reply->error() == QNetworkReply::NoError) {
        retString = QString(reply->readAll());
        qDebug() << "HTTP request success : " << retString;
    }

    else
        qDebug() << "HTTP request failure : " << reply->errorString();

    return retString;
}
