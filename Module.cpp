#include "arduino.h"
#include "Module.h"
Module::Module(){
    _listSensors = (Sensor**)malloc(10 * sizeof(Sensor*));
    _channel = NULL;
  }
void Module::load(Sensor* sensor){
    int i=0;
    while(_listSensors[i]!= NULL){
      i++;
    }
    _listSensors[i] = sensor;
    }
void Module::setChannel(Channel* c){
  _channel = c;
}
Module::~Module(){
    delete _listSensors;
    }

