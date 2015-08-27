#ifndef QMLMODEL_H
#define QMLMODEL_H
//field numbers, depends on channel config in thingspeak
#define LED1 1
#define LED2 2
#define LED3 3
#define SEGMENT 4
#define S1 5
#define S2 6


#include <QObject>
#include "Channel.h"

using namespace ThingSpeak;
using namespace std;

class QmlModel : public QObject
{
    Q_OBJECT
public:
    explicit QmlModel( Channel &channel, QObject *parent = 0 );

signals:
    //can be sent from here, have to be handled under Connections (main.qml)
    void testSignal(QString message);
    void updateTemp(QString temp);

public slots:
    //sent from GUI, handled here
    void test(QString message);
    void switchLED(QString num);
    void setSEGMENT(QString num);

private:
    Channel &channel;
};

#endif // QMLMODEL_H
