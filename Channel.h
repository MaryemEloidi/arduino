#ifndef Channel_h
#define Channel_h
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <SPI.h>
#include <WiFi.h>
#include <WiFiUDP.h>
#include "Sensor.h"


int const TAILLE = 2;
class Channel{
  public:
    Channel();
    virtual void send(String entete[TAILLE], Value donnees[TAILLE])=0;
};
class LogChannel : public Channel
{
  public:
    LogChannel();
    void send(String entete[TAILLE], Value donnees[TAILLE]);
};

class WifiChannel : public Channel
{
  public:
    WifiChannel();
    void send(String entete[TAILLE], Value donnees[TAILLE]);
};
#endif
