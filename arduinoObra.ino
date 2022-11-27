#define TTP223B 4

int LED = 3;
int TRIG=10;
int ECO=9;
int duracion;
int distancia;
int toch;
int toq = 1;
int knekro(int b);

void setup()
{
  pinMode(LED,OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECO,INPUT);
  pinMode(TTP223B, INPUT);
  Serial.begin(9600);
}

void loop(){
  digitalWrite(TRIG,HIGH);
  digitalWrite(TRIG,LOW);
  duracion=pulseIn(ECO,HIGH);
  distancia=duracion/58.4;
  int toque = digitalRead(TTP223B);
  if( distancia > 0){
  Serial.print("dis:");Serial.println(distancia);
  Serial.print("tac:"); Serial.println(toque);
  if( distancia < 46 && toque == 1) {
    if(toq < 1)
      toq = 1;
    if(toq > 45)
      toq = 45;
    analogWrite(LED,knekro(toq));
    toq++;
  }
  if( distancia < 46 && toque == 0) {
    if(toq < 1)
      toq = 1;
    if(toq > 45)
      toq = 45;
    analogWrite(LED,knekro(toq));
    toq--;
  }
  if( distancia >= 46) {
    if(toq < 1)
      toq = 1;
    if(toq > 45)
      toq = 45;
    analogWrite(LED,LOW);
    toq--;
  }
  //Serial.print(distancia);Serial.print("-");Serial.println(digitalRead(TTP223B));
  }
  delay(100);
}
int knekro(int b) {
  int rta = b*255/45;
  //Serial.print(b);Serial.print("-");Serial.println(rta);
  return rta;  
}
