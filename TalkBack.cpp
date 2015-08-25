#include <QUrl>
#include <QNetworkReply>
#include <QDebug>

#include "TalkBack.h"

using namespace ThingSpeak;
static const QString talkbackCommandPath = "/talkbacks/%1/commands";

TalkBack::TalkBack(ApiManager &manager, tsid_t id, const QString &apiKey): manager(manager), id(id), apiKey(apiKey)
{
}

tsid_t TalkBack::addCommand(const QString &commandString, quint64 position)
{
    QString positionString = position != 0 ? QString::number(position) : "";

    // Create query
    QUrlQuery query;
    query.addQueryItem("api_key", apiKey);
    query.addQueryItem("command_string", commandString);
    query.addQueryItem("position", positionString);

    // Send request and parse the reply
    QString path = talkbackCommandPath.arg(QString::number(id));;
    QNetworkReply *reply = manager.sendPostRequestSync(path, query);
    id_t retVal = parseReplyForID(reply);
    delete reply;

    return retVal;
}

