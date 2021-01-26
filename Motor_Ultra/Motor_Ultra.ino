//Carrega a biblioteca do sensor ultrassonico
#include < ultrasonic.h> 

#define INTERVALO_LEITURA 250 //(ms)

#define PIN_BLUE_LED    16
#define PIN_GREEN_LED   17
#define PIN_motor      21

//sensor ultrasonico
#define PIN_TRIGGER   4
#define PIN_ECHO      5
 
//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(PIN_TRIGGER, PIN_ECHO);
 
void setup()
{
  Serial.begin(9600); // o otros 115200

  pinMode(PIN_BLUE_LED,   OUTPUT);
  pinMode(PIN_GREEN_LED,  OUTPUT);
  pinMode(PIN_motor,     OUTPUT);
  
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
 
    //recupera a distância atual lida pelo sensor
    distancia = getDistance();
 
 
//esse FOR tem como objetivo apagar todos os LEDS que estejam acesos.
   
  digitalWrite(PIN_BLUE_LED, LOW);
  digitalWrite(PIN_GREEN_LED, LOW);
 
  //el motor
  digitalWrite(PIN_motor, LOW);

//caso a distancia lida seja menor ou igual a 5, tomaremos como uma distância de perigo
  //então acenderemos o LED VERMELHO e ligaremos o BUZZER
  if( distancia <= 10 )
  {
    digitalWrite(PIN_BLUE_LED, HIGH);
    digitalWrite(PIN_motor, HIGH);
  }

  else if(distancia >= 35)
  {
    digitalWrite(PIN_GREEN_LED, HIGH);
  }

}
