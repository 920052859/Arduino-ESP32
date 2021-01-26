void setup() {
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}


void loop() {

  int sensor = analogRead(A5);
Serial.println(analogRead(sensor));
  if(sensor<25){
    digitalWrite(11,HIGH);

  }else{
    digitalWrite(11,LOW);

  }
      delay(10);  
}
