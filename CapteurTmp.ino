//programme initial pour lire un capteur de température

//declaration des variables constantes
const int sensorPin = A0; //pin connecté à la sortie digitale du capteur
const float baselineTemp = 20.0; //la température de base

//le setup
void setup(){
  Serial.begin(9600);// on initialise la liaison serie à 9600 bauds
  for(int pinNumber = 2; pinNumber<5; pinNumber++){//pour chaque LED(ici elles sont connectées au pins suivants : 2, 3 et 4)
    pinMode(pinNumber, OUTPUT);//mettre le comme sortie 
    digitalWrite(pinNumber, LOW);//eteint pour le moment
  }
}

//traitement
void loop(){
  int sensorVal = analogRead(sensorPin);//dans la variable locale: sensorVal, mettre la valeur retournée par la fonction analogRead() qui prend en argument le pin du capteur et retourne une repésentation de son voltage
  Serial.print("la valeur du capteur: ");//affichage de la chaine "la valeur du capteur"
  Serial.print(sensorVal);//afficher la valeur de sensorVal (le voltage récupéré)
  float voltage = (sensorVal/1024.0) * 5.0;//recupérer le vrai voltage du pin avec une formule mathématique
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C:");
  float temperature = (voltage - .5) * 100;//convertir le voltage en un degree de temperature en Celsius 
  Serial.println(temperature);//afficher la temperature
  //on va allummer une LED pour chaque 2 degrès de plus que la température de base
  if (temperature < baselineTemp){//Si la temperature est inférieure à la temperature de base qui est à 2 degrès on laisse les leds eteintes
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4){//Sinon si la temperature est entre la temperature de base +2 et la température de base + 4, allumer une led
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
  }
  else if(temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH); 
  }
  delay(100);
}

