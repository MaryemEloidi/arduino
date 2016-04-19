#include "arduino.h"
#include "Sensor.h"

Sensor::Sensor(int pin, char* type, int(* convertRawValue)(int)){
      _pin = pin;
      _type = type;
      _convertRawValue = convertRawValue;
    }
struct Value* Sensor::readSensor(){
  int analogpin = analogRead(_pin);
  struct Value* value = (struct Value*)malloc(sizeof(struct Value));
  value->typeSensor=_type;
  value->value= _convertRawValue(analogpin);

  return value;
}
Sensor::~Sensor()
{  
  delete[] _type;
      return;
}

int  convertTemperature(int sensorTmpVal){
  //char* buffer = (char*)malloc(sizeof(float));
  
  float voltage = (sensorTmpVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  //sprintf(buffer, "%f", temperature);
  //Serial.print(temperature);
  return temperature;
}

int convertLumiere(int sensorLumVal){
int lightpourcentage;
  if (sensorLumVal < 10) {
    lightpourcentage = 0;
  } else if (sensorLumVal < 200) {
    lightpourcentage = 20;
  } else if (sensorLumVal < 500) {
    lightpourcentage = 50;
  } else if (sensorLumVal < 800) {
    lightpourcentage = 80;
  } else {
    lightpourcentage = 100;
  }
return lightpourcentage;
}


