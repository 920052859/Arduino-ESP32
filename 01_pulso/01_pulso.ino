int pulso=0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(A5,INPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulso=analogRead(A5);
  if(pulso>=600){

      digitalWrite(11,HIGH);
      delay(30);
      digitalWrite(11,LOW);
}
    delay(50);
    Serial.println(pulso);
}
