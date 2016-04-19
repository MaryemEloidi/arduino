#include "Sensor.h" 
Sensor* sensorTmp = new Sensor(A0, "temperature", &convertTemperature);
void setup() {
Serial.begin(9600);
}

void loop() {
  Value* valueTmp = sensorTmp->readSensor();
  Serial.print(valueTmp->value);
  Serial.print(valueTmp->typeSensor);
  delay(3000);

}

