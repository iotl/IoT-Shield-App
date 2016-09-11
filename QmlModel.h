#ifndef QMLMODEL_H
#define QMLMODEL_H
//field numbers, depends on channel config in thingspeak
#define LED1 1
#define LED2 2
#define LED3 3
#define SEGMENT 4
#define S1 5
#define S2 6
#define DEBUG 0


#include <QObject>
#include "Channel.h"
#include "TalkBack.h"

using namespace ThingSpeak;
using namespace std;

class QmlModel : public QObject
{
  Q_OBJECT
public:
  explicit QmlModel( Channel &channel, TalkBack &talkback, QObject *parent = 0 );

signals:
  //can be sent from here, have to be handled under Connections (main.qml)
  /**
     * @brief updates the temperature label in the gui
     * @param temp content string for label update
     */
  void updateTemp(QString temp);

  /**
     * @brief newEvent puts a new item in a event list, which contains an
     *        info icon an the message
     * @param message
     * @param eventType "buttonPressed", for now
     */
  void newEvent(QString message, QString eventType = 0 );

public slots:
  //sent from GUI, handled here
  void switchLED(int idx, QString toState);
  void setSEGMENT(QString toNumber);

  void update();

private:
  Channel &channel;
  TalkBack &talkback;
};

#endif // QMLMODEL_H
