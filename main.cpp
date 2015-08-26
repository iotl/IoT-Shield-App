#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Channel.h"
#include "TalkBack.h"

using namespace ThingSpeak;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QString str;
    ApiManager manager(ApiManager::apiUrlDefault);

    Channel channel(manager, 52473);
    channel.setWriteApiKey("SSZQ72F4VTZW43YS");
    channel.setReadApiKey("6EVT4HGIMKGPYYML");

    // Post new entry
    channel.updateChannelFieldFeed(1, "42");

    // Get last entry
    str = channel.getLastFieldFeedEntry(1);
    qDebug() << QString("Last field feed entry : %1").arg(str);

    // Talkback
    TalkBack talkBack(manager, 3092, "WDE49XOAQE08C604");

    // Add new TalkBack command
    talkBack.addCommand("LED_1_ON");

    // Execute talkback command
    str = talkBack.executeNextCommand();
    qDebug() << "Execute command : " << str;

    return app.exec();
}

