#include "QmlModel.h"
#include <QtDebug>

QmlModel::QmlModel( Channel &channel, QObject *parent) : channel(channel), QObject(parent)
{
}

void QmlModel::test(QString message)
{
    qDebug() << QString("Called Slot with message %1").arg(message);
    this->updateTemp("Here take this!");
    this->newEvent("hello from c++!!", "buttonPressed");
}

void QmlModel::switchLED(int idx, QString toState) {
    qDebug() << QString("Switch LED %1 %2").arg(QString::number(idx), toState);

    //get corresponding field number of the field channel
    int fieldNum;
    if(idx == 1) fieldNum = LED1;
    else if (idx == 2) fieldNum = LED2;
    else if (idx == 3) fieldNum = LED3;
    else return;

    //check field state and toggle on this behalf
//    int lastValue = channel.getLastFieldFeedEntry(fieldNum).toInt();
//    if ( lastValue == 0)
//        channel.updateChannelFieldFeed(fieldNum, "1");
//    else
//        channel.updateChannelFieldFeed(fieldNum, "0");
//    qDebug() << QString("Last Value was %1").arg(lastValue);

    // return here because update channel doesn't run in parallel
    if(DEBUG) return;

    //send state indicator to channel
    if (toState == QString("On")) {
      channel.updateChannelFieldFeed(fieldNum, "1");
    }else /* if (toState == QString("Off")) */ {
      channel.updateChannelFieldFeed(fieldNum, "0");
    }
}

void QmlModel::setSEGMENT(QString toNumber){
    qDebug() << QString("Set 7 Segment to %1").arg(toNumber);

    if(DEBUG) return;

    channel.updateChannelFieldFeed(SEGMENT, toNumber);
}
