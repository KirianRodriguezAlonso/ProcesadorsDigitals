#include <Arduino.h>
char v;
char v2;

void setup() {
  Serial.begin(115200);
  Serial2.begin(115200); 
}

void loop() {
  if(Serial.available()){
    v = Serial.read();
    Serial2.write(v);
    delay(2);
      if(Serial2.available()){

      v2 = Serial2.read();
      Serial.write(v2);
      }
  }
}