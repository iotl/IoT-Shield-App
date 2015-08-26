#include <QUrl>
#include <QNetworkReply>
#include <QDebug>

#include "TalkBack.h"

using namespace std;
using namespace ThingSpeak;

TalkBack::TalkBack(ApiManager &manager): manager(manager)
{ }

tsid_t TalkBack::addCommand(const QString &commandString, quint64 position)
{
    // If the position is given, convert it to a string otherwise left empty.
    QString positionString;
    if (position != 0)
        positionString = QString::number(position);

    // Create query
    QUrlQuery query;
    query.addQueryItem("api_key", apiKey);
    query.addQueryItem("command_string", commandString);
    query.addQueryItem("position", positionString);

    // Send request and parse the reply
    QString path = QString("/talkbacks/%1/commands").arg(id);
    unique_ptr<QNetworkReply> reply(manager.sendPostRequestSync(path, query));

    return parseReplyForID(reply.get());
}

QString TalkBack::executeNextCommand()
{
    // Create query
    QUrlQuery query;
    query.addQueryItem("api_key", apiKey);

    // Send request and return reply
    QString path = QString("/talkbacks/%1/commands/execute").arg(id);
    unique_ptr<QNetworkReply> reply (manager.sendGetRequestSync(path, query));

    return parseReplyForString(reply.get());
}

void TalkBack::setId(const tsid_t &value)
{
    id = value;
}

void TalkBack::setApiKey(const QString &value)
{
    apiKey = value;
}

tsid_t TalkBack::getId() const
{
    return id;
}

