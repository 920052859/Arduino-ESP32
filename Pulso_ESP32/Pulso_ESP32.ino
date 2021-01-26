int pulso=0;
int A50 = 12;
int LED1 = 13;
void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(A50,INPUT);
pinMode(LED1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulso=analogRead(A50);
  if(pulso>=600){

      digitalWrite(LED1,HIGH);
      delay(30);
      digitalWrite(LED1,LOW);
}
    delay(50);
    Serial.println(pulso);
}
