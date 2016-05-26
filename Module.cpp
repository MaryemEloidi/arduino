#include "arduino.h"
#include "Module.h"
/* Classe Module  
 * qui synchronise la lecture d'un ensmble de capteurs
 */
 /* Le constructeur */
Module::Module(){
    _listSensors = (Sensor**)malloc(10 * sizeof(Sensor*));
    _channel = NULL;
  }
/* la fonction Load ajoute un sensor au module
 * @param sensor : le capteur à ajouter
 */ 
void Module::load(Sensor* sensor){
    int i=0;
    while(_listSensors[i]!= NULL){
      i++;
    }
    _listSensors[i] = sensor;
    }
/* la fonction seChannel définit un canal de communication pour le module 
 * @param c le canal de communication
 */
void Module::setChannel(Channel* c){
  _channel = c;
}
/* la fonction displayList affiche la liste des capteurs dans le module*/
void Module::displayList(){
  int i=0;
  while(_listSensors[i]!= NULL){
    Serial.print(_listSensors[i]->_type);
  }
}
/* la fonction update qui lit chaque capteur dans le module, agrège les objets Value dans un tableau pour envoyer le tout via le canal de communication définit dans le module*/
void Module::updateM(){
  assert(_channel != NULL);
  Value* v;
  String entete;
  int i=0;
  Value tabValueSensors [10];
  String entetes[10];
  while(_listSensors[i]!= NULL){
    Serial.print("dansboucle");
    v = _listSensors[i]->readSensor();
     tabValueSensors[i] = *v;
    entete = _listSensors[i]->_type;
    entetes[i] = entete;
    i++;
  }

  _channel->send(entetes,tabValueSensors);
  
  
}
/* Destructeur */
Module::~Module(){
    delete _listSensors;
    }

