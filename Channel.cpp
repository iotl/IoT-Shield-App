#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QRegularExpression>
#include <memory>

#include "Channel.h"

using namespace std;
using namespace ThingSpeak;

Channel::Channel(ApiManager &manager) : manager(manager)
{ }

bool Channel::checkFieldId(unsigned int fieldId) const
{
    if (fieldId > 0 && fieldId <= 8)
        return true;

    return false;
}

tsid_t Channel::updateChannelFieldFeed(unsigned int fieldId, const QString &fieldValue)
{
    if (!checkFieldId(fieldId))
        return kInvalidId;

    // Create query
    QUrlQuery query;
    query.addQueryItem("api_key", writeApiKey);
    query.addQueryItem(QString("field%1").arg(fieldId), fieldValue);

    // Create path
    QString path = "/update";

    // Send request and parse the reply
    unique_ptr<QNetworkReply> reply(manager.sendPostRequestSync(path, query));

    return parseReplyForID(reply.get());
}

QString Channel::getLastFieldFeedEntry(unsigned int fieldId)
{
    if (!checkFieldId(fieldId))
        return "";

    // Create query
    QUrlQuery query;
    if (readApiKey.length())
        query.addQueryItem("api_key", readApiKey);

    // Create path
    QString path = QString("/channels/%1/fields/%2/last").arg(id).arg(fieldId);

    // Send request and parse the reply
    unique_ptr<QNetworkReply> reply(manager.sendGetRequestSync(path, query));
    return parseReplyForString(reply.get());
}

void Channel::setWriteApiKey(const QString &value)
{
    writeApiKey = value;
}

void Channel::setReadApiKey(const QString &value)
{
    readApiKey = value;
}

tsid_t Channel::getId() const
{
    return id;
}

void Channel::setId(const tsid_t &value)
{
    id = value;
}


