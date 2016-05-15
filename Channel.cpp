#include "arduino.h"
#include "Channel.h"
/* la classe abstraite Channel permet d'emettre les données des capteurs sur un canal de communication particulier(log, wifi...)
 *  On définit ici l'implémentation WiFiChannel qui utilise le shield WiFi pour envoyer les données sur un serveur
 *  et l'implémentation LogChannel qui formatte et affiche les données sur la sortie standard
*/

/* constructeur */ 
Channel::Channel(){
}
/* constructeur */ 
LogChannel::LogChannel(){
}
/* constructeur */ 
WifiChannel::WifiChannel(){
}
/* la méthode send de la classe LogChannel*/
void LogChannel::send(String entete[TAILLE], Value donnees[TAILLE]){
  
  for(int i=0; i<TAILLE; i++){
  for(int j=0; j<TAILLE; j++){
     Serial.print( entete[i]);
     Serial.print(" type :");
     Serial.print(donnees[j].typeSensor);
     Serial.print(" valeur:");
     Serial.print(donnees[j].value);
    }
  }
}
/* la méthode send de la classe WifiChannel*/
void WifiChannel::send(String entete[TAILLE], Value donnees[TAILLE]){
/* Ensemble de variables importantes pour l'envoie de données via wifi shield
 * ssid[] network SSID  
 * pass[] network password
 * status le status radio du wifi
 * host[] adresse IP du host influxDB
 * port le port sur lequel ecoute le plugin InfluxDB UDP
 */
char  ssid[] = "ssid";
char  pass[] = "monpass";
int  status = WL_IDLE_STATUS; 
byte const host[] = {10, 0, 1, 11};
int const port = 8888;

WiFiUDP udp;
String ligne;
  Serial.println("Attempting to connect to WPA network...");
  status = WiFi.begin(ssid, pass);
 
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a WiFi connection");
    while(true);
  } 
  
  else {
    Serial.println("Connected to network");
    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
 
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
  }
  for(int i=0; i<TAILLE; i++){
  for(int j=0; j<TAILLE; j++){
    ligne = String(entete[i]+" type :"+donnees[j].typeSensor+" valeur:"+donnees[j].value);
    Serial.println(ligne);
    Serial.println("Sending UDP packet...");
    udp.beginPacket(host, port);
    udp.print(ligne);
    udp.endPacket();
    }
  }

}



