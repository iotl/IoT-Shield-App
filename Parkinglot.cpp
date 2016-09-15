#include "Parkinglot.h"

#include "QmlModel.h"

Parkinglot::Parkinglot(QmlModel& model) : model(model) {}

void Parkinglot::process(Events event)
{
  // input
  if(event == pay && credit <9) {
    credit++;
  }
  if(event == free) {
    credit = 0;
  }
  if(event == tick && (state == S4 || state == S5) && credit >= 1) {
    credit--;
  }

  // transition
  if(event == tick && state == S4 && credit == 1) {
    // special tick if only one credit left: enter alert state (S5)
    state = S5;
  } else {
    state = transitions[state][event];
  }

  // output
  switch(state)
  {
    case S0:
      model.setState(false, false, false, -1);
      break;
    case S1:
      model.setState(true, false, false, credit);
      break;
    case S2:
      model.setState(true, false, false, credit);
      break;
    case S3:
      model.setState(true, false, false, credit);
      break;
    case S4:
      model.setState(false, false, true, credit);
      break;
    case S5:
      model.setState(false, true, false, credit);
      break;
  }
}
