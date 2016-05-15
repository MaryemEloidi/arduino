#include "Sensor.h"
#include "Module.h"
#include "Channel.h"

/* programme main du projet*/

Channel* mlog = new LogChannel();
Sensor* sensorTmp = new Sensor(A0, "temperature", &convertTemperature);
Module* myModule = new Module();

void setup() {
  Serial.begin(9600);
  myModule->load(sensorTmp);
  myModule->displayList();
  myModule->setChannel(mlog);
}

void loop() {
 
  myModule->update();
  delay(3000);

}

