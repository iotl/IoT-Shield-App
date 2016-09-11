#ifndef CHANNEL_H
#define CHANNEL_H

#include <QString>
#include "ApiManager.h"
#include "ApiCommon.h"

namespace ThingSpeak
{

class FeedEntry
{
public:
    /**
     * @brief Calculate the age of this entry.
     * @return Number of seconds since this entry was created.
     */
    uint64_t getAge() const;

    /**
     * @brief Access a specific field of the entry.
     * @param fieldNumber The number of the field (1 to 8).
     * @throw std::out_of_range if the field index is out of range
     * @return A reference to the requested field which is valid as long as
     *         the entry is.
     */
    const QString& getField(uint8_t fieldNumber) const;

    friend class Channel;

private:
    QDateTime created;
    QString fields[8];

    FeedEntry() = default;
};

QDebug operator<<(QDebug debug, const FeedEntry& entry);

class Channel
{
public:
    /**
     * @brief Channel representation of an ThingSpeak Channel.
     * @param manager The ApiManager that handles network requests.
     */
    Channel(ApiManager &manager);

    /**
     * @brief Adds a new value to the Channel's field feed.
     * @param fieldNumber The number of the field.
     * @param val The value string of the field.
     * @return Returns the field id of the request or 0 if an error occured.
     */
    tsid_t updateChannelFieldFeed(unsigned int fieldNumber, const QString &value);

    /**
     * @brief Get the last entry in a Field Feed.
     * @note Read API key is required for private channels. @see setReadApiKey();
     * @param fieldNumber The number of the field.
     * @param val The value string of the field.
     * @return Returns the field id of the request or 0 if an error occured.
     */
     QString getLastFieldFeedEntry(unsigned int fieldNumber);

    /**
     * @brief Get the last entry of the channel
     * @note Read API key is required for private channels. @see setReadApiKey();
     * @throw std::runtime_error if the request or json parsing fails
     * @return The last entry in the channel as a FeedEntry object
     */
    FeedEntry getLastFeedEntry();

    /**
     * @brief setWriteApiKey Sets the key for API write requests access (HTTP POST, UPDATE, DELETE etc.)
     * @param readApiKey The read API key.
     */
    void setWriteApiKey(const QString &value);

    /**
     * @brief setReadApiKey Sets the key for API read requests (HTTP GET)
     * @param readApiKey The read API key.
     */
    void setReadApiKey(const QString &readApiKey);

    /**
     * @brief getId The channel id, important for queries.
     * @return Returns the channel id.
     */
    tsid_t getId() const;

    /**
     * @brief Sets the channel id. Must be set for queries like getLastFieldFeedEntry() etc.
     * @param value The channel id.
     */
    void setId(const tsid_t &value);

private:
    tsid_t id;
    QString readApiKey;
    QString writeApiKey;
    ApiManager &manager;

    /// Checks if the field id is within the accepted range.
    bool checkFieldId(unsigned int fieldId) const;
};

}

#endif // CHANNEL_H
