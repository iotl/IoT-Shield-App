#include "QmlModel.h"
#include <QtDebug>
#include <QTimer>

QmlModel::QmlModel( Channel &channel, TalkBack &talkback, QObject *parent) : QObject(parent), channel(channel), talkback(talkback)
{
    update();
}

void QmlModel::onButtonPressed(int idx) {
    if(idx == 1) {
        qDebug() << QString("Send 'pay' to talkback");
        newEvent("Send 'pay' to talkback");

        talkback.addCommand("pay");
    } else {
        qDebug() << QString("Send 'start' to talkback");
        newEvent("Send 'start' to talkback");

        talkback.addCommand("start");
    }
}

void QmlModel::update() {
    auto lastEntry = channel.getLastFeedEntry();

    qDebug() << "Get last channel entry: " << lastEntry;
    newEvent(QString("FeedEntry(%1s old,%2,%3)").arg(lastEntry.getAge()).arg(lastEntry.getField(1)).arg(lastEntry.getField(2)));

    updateTemp(lastEntry.getField(1));

    QTimer::singleShot(5000, this, SLOT(update()));
}
