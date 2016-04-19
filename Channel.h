#ifndef Channel_h
#define Channel_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "Sensor.h"

class Channel{
  public:
    Channel(char* _nom);
    virtual void send(char** entete, Value* donnees)=0;
  private:
  char * _nom;
};
class LogChannel : public Channel
{
  void send(char** entete, Value* donnees);
};

class WifiChannel : public Channel
{
  void send(char** entete, Value* donnees);
};
#endif
