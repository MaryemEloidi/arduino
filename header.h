#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include <assert.h>

//typedef char* (func_convert)(int);
struct Sensor_s{
  int pin;
  char* type;
  //func_convert* convertRawValue;
  int (* convertRawValue)(int);
};
typedef struct Sensor_s Sensor;

struct Reading_s {
  Sensor* sensor;
  int value;
};
typedef struct Reading_s Reading;
int* convertRawValue(int);
Sensor* declareSensor(int pin, char* type, int (* convertRawValue)(int));
Reading* readSensor(Sensor* sensor);
int convertTemperature(int sensorTmpVal);
int convertLumiere(int sensorLumVal);
