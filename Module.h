#ifndef Module_h
#define Module_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "Sensor.h"
#include "Channel.h"

class Module{
  public:
  Module();
  void load(Sensor* sensor);
  void setChannel(Channel* c);
  ~Module();
  private:
  Sensor** _listSensors;
  Channel* _channel;
  
};
#endif
