#ifndef QMLMODEL_H
#define QMLMODEL_H

#define DEBUG 0


#include <QObject>
#include "Channel.h"
#include "TalkBack.h"
#include "Parkinglot.h"

using namespace ThingSpeak;
using namespace std;

class QmlModel : public QObject
{
  Q_OBJECT
public:
  explicit QmlModel( Channel &channel, TalkBack &talkback, QObject *parent = 0 );

signals:

  void setState(bool redLed, bool yellowLed, bool greenLed, int credit);

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
  void newEvent(QString message);

public slots:
  void onButtonPressed(int idx);

  void update();
  void simulateLot();

private:
  Channel &channel;
  TalkBack &talkback;

  Parkinglot parkingLot;
  FeedEntry lastEntry;
};

#endif // QMLMODEL_H
