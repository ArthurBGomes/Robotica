const int PINO_ENA = 9;
const int PINO_ENB = 3;
const int PINO_IN1 = 7;
const int PINO_IN2 = 6;
const int PINO_IN3 = 5; 
const int PINO_IN4 = 4;
int i = 0;
const int TEMPO_ESPERA = 1000;
const int TEMPO_RAMPA = 30;
void setup() {
  // put your setup code here, to run once:
pinMode(PINO_ENA,OUTPUT);
pinMode(PINO_ENB,OUTPUT);
pinMode(PINO_IN1,OUTPUT);
pinMode(PINO_IN2,OUTPUT);
pinMode(PINO_IN3,OUTPUT);
pinMode(PINO_IN4,OUTPUT);


digitalWrite(PINO_IN1,LOW);
digitalWrite(PINO_IN2,LOW);
digitalWrite(PINO_IN3,LOW);
digitalWrite(PINO_IN4,LOW);
digitalWrite(PINO_ENA,LOW);
digitalWrite(PINO_ENB,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(PINO_IN1,LOW);
digitalWrite(PINO_IN2,HIGH);
digitalWrite(PINO_IN3,LOW);
digitalWrite(PINO_IN4,HIGH);
for(i = 0;i < 256;i =i+10){
  analogWrite(PINO_ENA,i);  
  analogWrite(PINO_ENB,i);
  delay(TEMPO_RAMPA);
}
for(i = 255;i >= 0;i =i-10){
  analogWrite(PINO_ENA,i);  
  analogWrite(PINO_ENB,i);
  delay(TEMPO_RAMPA);
}
delay(TEMPO_ESPERA);

digitalWrite(PINO_IN1,HIGH);
digitalWrite(PINO_IN2,LOW);
digitalWrite(PINO_IN3,HIGH);
digitalWrite(PINO_IN4,LOW);
for(i = 0;i < 256;i =i+10){
  analogWrite(PINO_ENA,i);  
  analogWrite(PINO_ENB,i);
  delay(TEMPO_RAMPA);
}
for(i = 255;i >= 0;i =i-10){
  analogWrite(PINO_ENA,i);  
  analogWrite(PINO_ENB,i);
  delay(TEMPO_RAMPA);
}
delay(TEMPO_ESPERA);
}