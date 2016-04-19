#ifndef Sensor_h
#define Sensor_h

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

class Sensor
{
  public:
    Sensor(int pin, char* type, int(* convertRawValue)(int));
    struct Value* readSensor();
    ~Sensor();
  private:
    int _pin;
    char* _type;
    int(* _convertRawValue)(int);
  };
struct Value
{
    int value;
    char * typeSensor;
  };
typedef struct Value Value;

int convertTemperature(int sensorTmpVal);
int convertLumiere(int sensorLumVal);
#endif

