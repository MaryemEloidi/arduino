#include <ArduinoJson.h>

/*Ce programme arduino lit les données récupérees avec le capteur de température et celui de la lumière 
ensuite il formate ces données sous la forme d'un fichier json et affiche cela dans le log d'arduino*/


//declaration des variables constantes pour les capteurs
const int tmpPin = A0; //pin connecté à la sortie digitale du capteur de température
const int lightPin = A1; //pin connecté à la sortie digitale du capteur de lumière

StaticJsonBuffer<200> jsonBuffer;

void setup(){
  Serial.begin(9600);// on initialise la liaison serie à 9600 bauds
}

//traitement
void loop(){
  int sensorTmpVal = analogRead(tmpPin);//dans la variable locale: sensorVal, mettre la valeur retournée par la fonction analogRead() qui prend en argument le pin du capteur et retourne une repésentation de son voltage
  int sensorlightReading = analogRead(lightPin); //reading light signal
  float voltage = (sensorTmpVal/1024.0) * 5.0;//recupérer le vrai voltage du pin avec une formule mathématique
  //Serial.print(", Volts: ");
  //Serial.print(voltage);
  //Serial.print(", degrees C:");
  float temperature = (voltage - .5) * 100;//convertir le voltage en un degree de temperature en Celsius 
  //Serial.println(temperature);//afficher la temperature
  //Serial.print("la valeur du capteur : light");
  //Serial.print(sensorlightReading);
  String light;
  if (sensorlightReading < 10) {
    light = "noir";
  } else if (sensorlightReading < 200) {
    light = "sombre";
  } else if (sensorlightReading < 500) {
    light = "peu lumineux";
  } else if (sensorlightReading < 800) {
    light = "lumineux";
  } else {
    light = "très lumineux";
  }
  JsonObject& donnees = jsonBuffer.createObject();
  JsonArray& array = jsonBuffer.createArray();
  JsonObject& Tmp = jsonBuffer.createObject();
  JsonObject& Slight = jsonBuffer.createObject();
  Tmp["Type"] = "Temperature";
  Tmp["Valeur"] = temperature;
  Slight["type"] = "lumiere";
  Slight["valeur"] = light;
  array.add(Tmp);
  array.add(Slight);
  donnees["Donnees recuperees"] = array; 
  donnees.prettyPrintTo(Serial);// pour un afffichage indenté lisible sinon utiliser printTo()
  delay(5000000);
}

