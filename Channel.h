#ifndef CHANNEL_H
#define CHANNEL_H

#include <QString>
#include "ApiManager.h"
#include "ApiCommon.h"

namespace ThingSpeak
{

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
