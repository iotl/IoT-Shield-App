#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <memory>

#include "Channel.h"
#include "TalkBack.h"
#include "QmlModel.h"

using namespace ThingSpeak;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;

    ApiManager manager;

    Channel channel(manager);
    channel.setId(666);
    channel.setWriteApiKey("AAAAAAAAAAAAAAAA");
    channel.setReadApiKey("AAAAAAAAAAAAAAAA");

    TalkBack talkback(manager);
    talkback.setId(666);
    talkback.setApiKey("AAAAAAAAAAAAAAAA");

    QmlModel model(channel, talkback);
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("modelHandler", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}

