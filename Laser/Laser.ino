#include <Wire.h>
#include <VL53L0X.h>
VL53L0X sensor;


void setup() {
  Serial.begin(9600);
  Wire.begin();
  sensor.init();
  sensor.setTimeout(500);

}

void loop() {
  int dist = sensor.readRangeSingleMillimeters();
  Serial.println(dist);
  delay(1000);
}
