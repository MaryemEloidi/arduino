#include "arduino.h"
#include "Channel.h"
Channel::Channel(char * nom){
  _nom = nom;
  }
void LogChannel::send(char** entete, Value* donnees){
}

void WifiChannel::send(char** entete, Value* donnees){
}


