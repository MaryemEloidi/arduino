#include "arduino.h"
#include "Sensor.h"
/* Classe Sensor */

/*Constructeur 
@param pin le pin auquel le capteur est attaché
@param type: le type du capteur 
@param * convertRawValue)(int): pointeur de fonction de conversion qui prend en param un entier et retourne un entier
*/
Sensor::Sensor(int pin, char* type, int(* convertRawValue)(int)){
      _pin = pin;
      _type = type;
      _convertRawValue = convertRawValue;
    }
/* fonction qui lit la valeur retournée par un capteur en faisant appel à la fonction de conversion passée passée en parametre lors de la construction de ce capteur
 *  @return value de type struct Value qui contient le type du capteur et sa valeur 
 */
struct Value* Sensor::readSensor(){
  int analogpin = analogRead(_pin);
  struct Value* value = (struct Value*)malloc(sizeof(struct Value));
  value->typeSensor=_type;
  value->value= _convertRawValue(analogpin);

  return value;
}
/*Destructeur*/
Sensor::~Sensor()
{  
  delete[] _type;
      return;
}
/* fonction qui convertie la valeur retournée par le capteur tmp en °C */
int  convertTemperature(int sensorTmpVal){
  float voltage = (sensorTmpVal/1024.0) * 5.0;
  float temperature = (voltage - .5) * 100;
  return temperature;
}
/* fonction qui convertie la valeur retournée par un capteur de lumiere en valeur entiere
 * 0 pour sombre
 * 20 pour peu lumineux
 * 50 pour lumineux
 * 80 très lumineux
 */
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


