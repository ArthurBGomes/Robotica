#include <Ultrasonic.h>
#define trigPino 13
#define echoPino 12
Ultrasonic Sensor(trigPino,echoPino);
long dist;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPino,OUTPUT);        
pinMode(echoPino,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
dist = Sensor.Ranging(CM);
Serial.print(dist);
Serial.println("cm");
delay(500);
}
