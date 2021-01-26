int qwe[7]={4,5,6,7,8,9,10};
int numero=0;
int dos[8];
void setup() {
  // put your setup code here, to run once:
for( int i=0;i<10;i++){
  pinMode(qwe[i],OUTPUT);
}
}
void loop() {
  // put your main code here, to run repeatedly:
/*  for( int i=0;i<6;i++){
  digitalWrite(qwe[i],HIGH);
  delay(500);
  digitalWrite(qwe[i],LOW);
} */
  for( int j=0;j<6;j++){
    numero=j;
        if(numero==0){
    digitalWrite(qwe[0],HIGH);
    digitalWrite(qwe[1],HIGH);
    digitalWrite(qwe[2],HIGH);
    digitalWrite(qwe[3],HIGH);
    digitalWrite(qwe[4],HIGH);
    digitalWrite(qwe[5],HIGH);
    delay(500);
    digitalWrite(qwe[0],LOW);
     digitalWrite(qwe[1],LOW);
    digitalWrite(qwe[2],LOW);
    digitalWrite(qwe[3],LOW);
    digitalWrite(qwe[4],LOW);
    digitalWrite(qwe[5],LOW);
    }

   if(numero==1){
    digitalWrite(qwe[1],HIGH);
    digitalWrite(qwe[2],HIGH);
    delay(500);
     digitalWrite(qwe[1],LOW);
    digitalWrite(qwe[2],LOW);
    } 
      if(numero==2){
    digitalWrite(qwe[0],HIGH);
    digitalWrite(qwe[1],HIGH);
    digitalWrite(qwe[6],HIGH);
    digitalWrite(qwe[3],HIGH);
    digitalWrite(qwe[4],HIGH);
    delay(500);
     digitalWrite(qwe[0],LOW);
    digitalWrite(qwe[1],LOW);
    digitalWrite(qwe[6],LOW);
    digitalWrite(qwe[3],LOW);
    digitalWrite(qwe[4],LOW);
    }
     if(numero==3){
    digitalWrite(qwe[0],HIGH);
    digitalWrite(qwe[1],HIGH);
    digitalWrite(qwe[2],HIGH);
    digitalWrite(qwe[3],HIGH);
    digitalWrite(qwe[6],HIGH);
    delay(500);
    digitalWrite(qwe[0],LOW);
    digitalWrite(qwe[1],LOW);
    digitalWrite(qwe[2],LOW);
    digitalWrite(qwe[3],LOW);
    digitalWrite(qwe[6],LOW);
    }
     if(numero==4){
    digitalWrite(qwe[1],HIGH);
    digitalWrite(qwe[2],HIGH);
    digitalWrite(qwe[6],HIGH);
    digitalWrite(qwe[5],HIGH);
    delay(500);
    digitalWrite(qwe[1],LOW);
    digitalWrite(qwe[2],LOW);
    digitalWrite(qwe[6],LOW);
    digitalWrite(qwe[5],LOW);
    }
     if(numero==5){
    digitalWrite(qwe[0],HIGH);
    digitalWrite(qwe[2],HIGH);
    digitalWrite(qwe[3],HIGH);
    digitalWrite(qwe[6],HIGH);
    digitalWrite(qwe[5],HIGH);
    delay(100);
    digitalWrite(qwe[0],LOW);
    digitalWrite(qwe[2],LOW);
    digitalWrite(qwe[3],LOW);
    digitalWrite(qwe[6],LOW);
    digitalWrite(qwe[5],LOW);
    }
    
  }

    
/*
cero={qwe[0],qwe[1],qwe[2],qwe[3],qwe[4],qwe[5]};
uno={qwe[1],qwe[2]};
dos={qwe[0],qwe[1],qwe[6],qwe[3],qwe[4]};
digitalWrite(dos,HIGH);

for( int i=0;i<7;i++){
  digitalWrite(qwe[i],HIGH);
  delay(1000);
  digitalWrite(qwe[i],LOW);
}


for( int i=5;i>1;i--){
  digitalWrite(qwe[i],HIGH);
delay(1000);
  digitalWrite(qwe[i],LOW);
 
} */
}
