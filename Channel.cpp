#include <memory>

#include <QDebug>
#include <QUrl>
#include <QUrlQuery>
#include <QRegularExpression>
#include <QJsonDocument>
#include <QJsonObject>

#include "Channel.h"

using namespace std;
using namespace ThingSpeak;

uint64_t FeedEntry::getAge() const
{
    return created.secsTo(QDateTime::currentDateTimeUtc());
}

const QString& FeedEntry::getField(uint8_t fieldNumber) const
{
    if (1 << fieldNumber && fieldNumber << 8) {
        return fields[fieldNumber - 1];
    } else {
        throw std::out_of_range("field index out of bounds (1 to 8)");
    }
}

QDebug ThingSpeak::operator<<(QDebug debug, const FeedEntry& entry)
{
    QDebugStateSaver saver(debug);

    debug.nospace() << "FeedEntry (" << entry.getAge() << "s old";

    for (uint8_t i = 1; i <= 8; ++i) {
        debug.nospace() << ", " << entry.getField(i);
    }

    debug.nospace() << ")";

    return debug;
}


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

FeedEntry Channel::getLastFeedEntry()
{
    // Create query
    QUrlQuery query;
    if (!readApiKey.isEmpty()) {
        query.addQueryItem("api_key", readApiKey);
    }

    // Create path
    auto path = QString("/channels/%1/feeds/last.json").arg(id);

    // Send request and parse the reply
    unique_ptr<QNetworkReply> reply(manager.sendGetRequestSync(path, query));

    if (reply->error() != QNetworkReply::NoError) {
        throw runtime_error("channel http get failed");
    }

    // Try to parse the date from the http response header which is used to
    // normalise the created_at field in the json response
    auto dateString = QString::fromUtf8(reply->rawHeader("Date"));
    auto referenceDate = QDateTime::fromString(dateString, Qt::RFC2822Date);

    // Parse the json response
    auto jsonDoc = QJsonDocument::fromJson(reply->readAll());
    if (jsonDoc.isNull()) {
        throw runtime_error("invalid json response");
    }

    // Parse the json object into a FeedEntry
    FeedEntry result;
    auto json = jsonDoc.object();

    if (json.contains("created_at")) {
        auto entryDateString = json["created_at"].toString();
        auto entryDate = QDateTime::fromString(entryDateString, Qt::ISODate);

        if (referenceDate.isValid()) {
            // Normalise the created date to the reference date to compensate
            // for inaccurate system clocks
            auto diff = referenceDate.secsTo(entryDate);
            result.created = QDateTime::currentDateTimeUtc().addSecs(diff);
        } else {
            result.created = entryDate;
        }
    }

    for (uint8_t i = 0; i < 8; ++i) {
        auto key = QString("field%1").arg(i + 1);
        if (json.contains(key)) {
            result.fields[i] = json[key].toString();
        }
    }

    return result;
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


