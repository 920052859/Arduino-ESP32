void subir(){
  digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
}
void bajar(){
  digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
void girari(){
 digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
}
void girard(){
 digitalWrite(3,HIGH);
    digitalWrite(2,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(4,LOW);
}
void parar(){
 for( int i=2;i<6;i++){
  digitalWrite(i,LOW);
}

}
const int Trigger = 11;   //Pin digital 11 para el Trigger del sensor
const int Echo = 10;   //Pin digital 10 para el echo del sensor
 int t;
void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  for( int i=2;i<6;i++){
  pinMode(i,OUTPUT);
}

 pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
}

void loop() {
   digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

 t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  // put your main code here, to run repeatedly:
  Serial.println(t*170);

}
