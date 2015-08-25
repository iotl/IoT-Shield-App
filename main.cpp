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

    ApiManager manager(ApiManager::apiUrlDefault);

    /*
    Channel channel(manager, "SSZQ72F4VTZW43YS");
    channel.postField(1, "42");
    channel.postField(1, "43");
    */

    TalkBack talkBack(manager, 3092, "WDE49XOAQE08C604");
    talkBack.addCommand("LED_1_ON");

    return app.exec();
}

