#include <Servo.h>
#define SERVO 6
Servo s;
int pos;
void setup() {
  // put your setup code here, to run once:
s.attach(SERVO);
Serial.begin(9600);
s.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
for(pos = 0;pos < 180;pos++){
  s.write(pos);
  Serial.println(pos);
  delay(15);
}
for(pos = 180;pos >= 0;pos--){
  s.write(pos);
  Serial.println(pos);
  delay(15);
}
}
