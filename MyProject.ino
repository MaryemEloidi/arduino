#include "Sensor.h"
#include "Module.h"
#include "Channel.h"

/* programme main du projet*/

Channel* mlog = new LogChannel();
Sensor* sensorTmp = new Sensor(A0, "temperature", &convertTemperature);
Sensor* sensorLum = new Sensor(A2, "Lumiere", &convertLumiere);
Module* myModule = new Module();

void setup() {
  Serial.begin(9600);
  
}

void loop() {
 myModule->load(sensorTmp);
 myModule->load(sensorLum);
 myModule->setChannel(mlog);
 myModule->updateM();
 delay(300000);

}

