pinMode(11,OUTPUT);
tiempo1 = millis();
}

void loop() {
  
  // put your main code here, to run repeatedly:
  tiempo2 = millis();
  pulso=analogRead(A5);
  if(pulso>=550){
     if(tiempo2 <(tiempo1+60000)){
    npulso=npulso+1;
    } else {
      delay(50);
      Serial.println(npulso);
     pulso=0;
      }
    tiempo1 = millis();
      digitalWrite(11,HIGH);
      delay(17);
      digitalWrite(11,LOW);
  
}
    delay(50);
    Serial.println(pulso);
