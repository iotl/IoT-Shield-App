#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <channel.h>

using namespace ThingSpeak;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    ApiManager mgr(ApiManager::API_URL_DEFAULT);

    Channel channel(mgr, "SSZQ72F4VTZW43YS");
    channel.postField(1, "42");
    channel.postField(1, "43");

    return app.exec();
}

