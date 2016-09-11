#include "QmlModel.h"
#include <QtDebug>

QmlModel::QmlModel( Channel &channel, TalkBack &talkback, QObject *parent) : QObject(parent), channel(channel), talkback(talkback)
{
}

void QmlModel::switchLED(int, QString) {
    qDebug() << QString("Send 'start' to talkback");
    newEvent("Send 'start' to talkback");

    talkback.addCommand("start");
}

void QmlModel::setSEGMENT(QString){
    qDebug() << QString("Send 'pay' to talkback");
    newEvent("Send 'pay' to talkback");

    talkback.addCommand("pay");
}

}
