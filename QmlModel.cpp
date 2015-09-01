#include "QmlModel.h"
#include <QtDebug>

QmlModel::QmlModel( Channel &channel, QObject *parent) : channel(channel), QObject(parent)
{
}

void QmlModel::test(QString message)
{
    qDebug() << QString("Called Slot wit message %1").arg(message);
    this->updateTemp("Here take this!");
}

void QmlModel::switchLED(QString ledNum) {//TODO: check if box is checked?!
    qDebug() << QString("Switch LED %1").arg(ledNum);
    int fieldNum;
    if(ledNum.toInt() == 1) fieldNum = LED1;
    else if (ledNum.toInt() == 2) fieldNum = LED2;
    else if (ledNum.toInt() == 3) fieldNum = LED3;
    else return;

    //check if im on or off and then toggle
    int lastValue = channel.getLastFieldFeedEntry(fieldNum).toInt();
    if ( lastValue == 0)
        channel.updateChannelFieldFeed(fieldNum, "1");
    else
        channel.updateChannelFieldFeed(fieldNum, "0");

    qDebug() << QString("Last Value was %1").arg(lastValue);
}

void QmlModel::setSEGMENT(QString num){
    qDebug() << QString("Set 7 Segment to %1").arg(num);
    channel.updateChannelFieldFeed(SEGMENT, num);
}

