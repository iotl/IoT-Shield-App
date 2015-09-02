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

    QString str;
    ApiManager manager;

    Channel channel(manager);
    channel.setId(52473);
    channel.setWriteApiKey("SSZQ72F4VTZW43YS");
    channel.setReadApiKey("6EVT4HGIMKGPYYML");
//    channel.setId(53583);
//    channel.setWriteApiKey("T8ZR0O9IVJYFQN0G");
//    channel.setReadApiKey("AXH33DEAGAB4YBD0");

    QmlModel model(channel);
    QQmlContext *context = engine.rootContext();
    context->setContextProperty("modelHandler", &model);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // Post new entry
    //channel.updateChannelFieldFeed(1, "42");

    // Get last entry
//    str = channel.getLastFieldFeedEntry(1);
//    qDebug() << QString("Last field feed entry : %1").arg(str);

    // Talkback
    // TalkBack talkBack(manager);
    // talkBack.setId(3092);
    // talkBack.setApiKey("WDE49XOAQE08C604");

    // Add new TalkBack command
    // talkBack.addCommand("LED_1_ON");

    // Execute talkback command
    // str = talkBack.executeNextCommand();
    // qDebug() << "Execute command : " << str;

    return app.exec();
}

