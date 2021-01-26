#include <ETH.h>
#include <WiFi.h>
#include <WiFiAP.h>
#include <WiFiClient.h>
#include <WiFiGeneric.h>
#include <WiFiMulti.h>
#include <WiFiScan.h>
#include <WiFiServer.h>
#include <WiFiSTA.h>
#include <WiFiType.h>
#include <WiFiUdp.h>

#include <Ultrasonic.h>

#include <PubSubClient.h>
#include <Adafruit_CircuitPlayground.h>
#include <Adafruit_Circuit_Playground.h>

/****************************************
 * Include Libraries
 *no te olvides crear una cuenta n ubidots
 ****************************************/
//Carrega a biblioteca do sensor ultrassonico
#include <ultrasonic.h> 
#define WIFISSID "WLAN_AF09" //  WifiSSID
#define PASSWORD "a6V9p3R5q0a8e" // password 
#define TOKEN "BBFF-i6upBSOaRTYWEkDImDSLhh47OGfzbN" // Put your Ubidots' TOKEN
#define MQTT_CLIENT_NAME "corina18" // MQTT client Name, please enter your own 8-12 alphanumeric character ASCII string; 
                                           //it should be a random and unique ascii string and different from all other devices

/****************************************
 * Define Constants
 ****************************************/
#define VARIABLE_LABEL "sensor" // Assing the variable label
#define DEVICE_LABEL "esp32" // Assig the device label

#define INTERVALO_LEITURA 250 //(ms)

#define PIN_BLUE_LED    26
#define PIN_GREEN_LED   27
#define PIN_MOTOR      21

//sensor ultrasonico
#define PIN_TRIGGER   4
#define PIN_ECHO      5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(PIN_TRIGGER, PIN_ECHO);

/****************************************
 * Auxiliar Functions
 ****************************************/
WiFiClient ubidots;
PubSubClient client(ubidots);
 
void callback(char* topic, byte* payload, unsigned int length) {
  char p[length + 1];
  memcpy(p, payload, length);
  p[length] = NULL;
  String message(p);
  Serial.write(payload, length);
  Serial.println(topic);
}
void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    
    // Attemp to connect
    if (client.connect(MQTT_CLIENT_NAME, TOKEN, "")) {
      Serial.println("Connected");
    } else {
      Serial.print("Failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 2 seconds");
      // Wait 2 seconds before retrying
      delay(2000);
    }
  }
}

 
void setup()
{
  Serial.begin(115200); // o otros 115200  ó 9600

  pinMode(PIN_BLUE_LED,   OUTPUT);
  pinMode(PIN_GREEN_LED,  OUTPUT);
  pinMode(PIN_MOTOR,     OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  verificarDistancia();
  delay(INTERVALO_LEITURA);
  
}

int getDistance()
{
    //faz a leitura das informacoes do sensor (em cm)
    int distanciaCM;
    long microsec = ultrasonic.timing();
    // pode ser um float ex: 20,42 cm se declarar a var float 
    distanciaCM = ultrasonic.convert(microsec, Ultrasonic::CM);
  
    return distanciaCM;
}

void verificarDistancia()
{
    //pedir la distancia uwu
    distancia = getDistance();

  digitalWrite(PIN_BLUE_LED, LOW);
  digitalWrite(PIN_GREEN_LED, LOW);
 
  //el motor
  digitalWrite(PIN_MOTOR, LOW);

//caso a distancia lida seja menor ou igual a 5, tomaremos como uma distância de perigo
  //então acenderemos o LED VERMELHO e ligaremos o BUZZER
  if( distancia <= 5 )
  {
    digitalWrite(PIN_BLUE_LED, HIGH);
  }

  else if(distancia >= 20)
  {
    digitalWrite(PIN_GREEN_LED, HIGH);
    digitalWrite(PIN_MOTOR, HIGH);
  }
sensor=float(float((20-distancia)*100)/float(20));
}

  if (!client.connected()) {
    reconnect();
  }
 
  sprintf(topic, "%s%s", "/v1.6/devices/", DEVICE_LABEL);
  sprintf(payload, "%s", ""); // Cleans the payload
  sprintf(payload, "{\"%s\":", VARIABLE_LABEL); // Adds the variable label
  
  //float sensor = random(0,100);//analogRead(SENSOR); 
  Serial.print("Sensor:");
  Serial.println(sensor);
  /* 4 is mininum width, 2 is precision; float value is copied onto str_sensor*/
  dtostrf(sensor, 4, 2, str_sensor);
  
  sprintf(payload, "%s {\"value\": %s}}", payload, str_sensor); // Adds the value
  Serial.println("Publishing data to Ubidots Cloud");
  client.publish(topic, payload);
  client.loop();
  delay(4000);
}
