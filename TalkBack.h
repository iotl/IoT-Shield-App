#ifndef TALKBACK_H
#define TALKBACK_H

#include <QString>
#include "ApiManager.h"
#include "ApiCommon.h"

namespace ThingSpeak {

class TalkBack
{
public:
    TalkBack(ApiManager &manager);

    tsid_t addCommand(const QString &commandString, quint64 position = 0);

    /**
     * @brief executeNextCommand Executes the next TalkBack command in the queue.
     * @return Returns the command string.
     */
    QString executeNextCommand();

    /**
     * @brief The TalkBack ID.
     * @return Returns the ID of this TalkBack.
     */
    tsid_t getId() const;

    /**
     * @brief Sets the TalkBack id.
     * @param value The TalkBack id for HTTP requests
     */
    void setId(const tsid_t &value);

    /**
     * @brief The API key for this TalkBack.
     * @param value The API key to for HTTP requests.
     */
    void setApiKey(const QString &value);


private:
    tsid_t id;
    QString apiKey;
    ApiManager &manager;
};
}

#endif // TALKBACK_H
