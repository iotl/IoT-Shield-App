#ifndef PARKINGLOT_H
#define PARKINGLOT_H

class QmlModel;

class Parkinglot
{
  public:
    enum Events {ready, free, pay, start, tick}; //Eingabealphabet
    enum States {S0,S1,S2,S3,S4,S5};

    States state = S0;
    unsigned int credit;

    Parkinglot(QmlModel& model);

    void process(Events event);

  private:
    QmlModel& model;

    States transitions[6][5] =
//    ready, free, pay, start, tick
      {{S1,  S0,   S0,  S0,    S0}, //S0
      { S1,  S0,   S2,  S1,    S1}, //S1
      { S2,  S0,   S3,  S5,    S2}, //S2
      { S3,  S0,   S3,  S4,    S3}, //S3
      { S4,  S0,   S3,  S4,    S4}, //S4
      { S5,  S0,   S3,  S5,    S1}};//S5
};

#endif
