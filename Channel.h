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
     * @brief Creates a channel representation
     * @param manager The ApiManager that handles the requests.
     * @param apiKey The unique API key of the channel.
     */
    Channel(ApiManager &manager, QString apiKey);

    /**
     * @brief Send a HTTP post request to the api with the given field value.
     * @param fieldNumber The number of the field.
     * @param val The value string of the vield.
     * @return Returns the field id of the request or 0 if an error occured.
     */
    tsid_t postField(unsigned int fieldNumber, const QString &value);

private:
    ApiManager &manager;
    const QString apiKey;
    QString updatePath;

    /// Checks if the field id is within the accepted range.
    bool checkFieldId(unsigned int fieldId) const;
};

}

#endif // CHANNEL_H
