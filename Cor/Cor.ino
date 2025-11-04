#include <Wire.h>
#include"Adafruit_TCS34725.h"
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_300MS,TCS34725_GAIN_1X);

void setup() {
  Serial.begin(9600);
  tcs.begin();

}

void loop() {
  uint16_t r,g,b,c;
  if(tcs.begin()){
    tcs.getRawData(&r,&g,&b,&c);
  }
  if (r>b&&r>g){
    Serial.println("VERMELHO"); Serial.print("\t");Serial.print(r);Serial.print("\t");Serial.print(g);
    Serial.print("\t"); Serial.println(b);
  }
  else if (g>r&&g>b){
    Serial.println("VERDE");Serial.print("\t");Serial.print(r);Serial.print("\t");Serial.print(g);
    Serial.print("\t");Serial.println(b);
  }
  else if (b>r&&b>g){
     Serial.println("AZUL");Serial.print("\t");Serial.print(r);Serial.print("\t");Serial.print(g);
    Serial.print("\t");Serial.println(b);
  }
  delay(1000);
}