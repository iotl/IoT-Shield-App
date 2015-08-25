#ifndef CHANNEL_H
#define CHANNEL_H

#include <QString>
#include "apimanager.h"

namespace ThingSpeak
{

class Channel
{
public:
    enum {
        kPostError = 0,
    } ChannelResponse;



    static const QString updatePathDefault;

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
     * @return Returns the id number of the update or kPostError if an error occured.
     */
    unsigned int postField(unsigned int fieldNumber, const QString &value);

private:
    ApiManager &manager;
    QString apiKey;
    QString updatePath;

    /// Checks if the field id is within the accepted range.
    bool checkFieldId(unsigned int fieldId) const;

    /// Parses the reply of the an HTTP post request.
    unsigned int parseFieldPostReply(QNetworkReply *reply) const;
};

}

#endif // CHANNEL_H
