#include "QmlModel.h"
#include <QtDebug>
#include <QTimer>

#include "Parkinglot.h"

QmlModel::QmlModel( Channel &channel, TalkBack &talkback, QObject *parent) : QObject(parent), channel(channel), talkback(talkback), parkingLot(*this)
{
    update();

    QTimer *timer = new QTimer(this);
    connect(timer, QTimer::timeout, this, QmlModel::simulateLot);
    timer->start(500);
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
    lastEntry = channel.getLastFeedEntry();

    qDebug() << "Get last channel entry: " << lastEntry;
    newEvent(QString("FeedEntry(%1s old,%2,%3)").arg(lastEntry.getAge()).arg(lastEntry.getField(1)).arg(lastEntry.getField(2)));

    updateTemp(lastEntry.getField(1));
    simulateLot();

    QTimer::singleShot(5000, this, SLOT(update()));
}

void QmlModel::simulateLot() {
    parkingLot.state = (Parkinglot::States) lastEntry.getField(3).toInt();
    parkingLot.credit = lastEntry.getField(4).toInt();

    unsigned int ticks = lastEntry.getAge() / 4;
    for(unsigned int i = 0; i < ticks; ++i) {
        parkingLot.process(Parkinglot::tick);
    }
}
