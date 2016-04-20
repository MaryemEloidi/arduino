#include "header.h" 
const int tmpPin = A0;
/*int sensorTmpVal = analogRead(A0);
int sensorlightVal = analogRead(A1);*/
void setup() {
Serial.begin(9600);
}

void loop() {
Sensor* sensorTmp = declareSensor(tmpPin, "temperature", &convertTemperature);
Reading* readingTmp = readSensor(sensorTmp);
Serial.print(readingTmp->sensor->pin);
Serial.println(" ");
Serial.print(readingTmp->sensor->type);
Serial.println(" ");
//Serial.print(analogRead(A0));
Serial.print(readingTmp->value);
Serial.println(" ");
//Serial.print(convertTemperature(analogRead(readingTmp->sensor->pin)));
//int re = convertTemperature(analogRead(A0));
//Serial.print(re);
delay(10000000);
}
  Reading* readSensor(Sensor* sensor){
  Reading* reading = (Reading*)malloc(sizeof(struct Reading_s));
  int res = analogRead(reading->sensor->pin);
  reading->sensor=sensor;
  reading->value=sensor->convertRawValue(res);

  return reading;
}

