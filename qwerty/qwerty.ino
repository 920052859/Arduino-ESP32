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






void setup() {
  for( int i=2;i<6;i++){
  pinMode(i,OUTPUT);
}
}

void loop() {
 parar();

}
