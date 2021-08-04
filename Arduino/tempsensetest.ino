#include <Wire.h>
#include <Adafruit_TMP117.h>
#include <Adafruit_Sensor.h>

Adafruit_TMP117  tmp117;

String verify;
void setup(void) {
  Serial.begin(115200);
  while (!Serial) delay(10);     // will pause Zero, Leonardo, etc until serial console opens
  // Try to initialize!
  if (!tmp117.begin()) {
    //Serial.println("Failed to find TMP117 chip");
    while (1) {
      delay(10);
    }
  }
  //Serial.println("TMP117 Found!");
  read_temp();

}

void read_temp() {
  while (!Serial.available()) {
    float f = 0;
    while (f < 95) {
      sensors_event_t temp; // create an empty event to be filled
      tmp117.getEvent(&temp); //fill the empty event object with the current measurements
      t = ((temp.temperature) * 1.8 ) + 32;
    }
    delay(5000);
    sensors_event_t reading; // create an empty event to be filled
    tmp117.getEvent(&reading);
    f = ((reading.temperature) * 1.8 ) + 32;
    if (f >= 95) {
      Serial.println(f);
    }
    delay(5000);
  }
  if (Serial.available()){
    
  }
  //in the fuure, could have an LED light up to verify temperaturewas taken when Raspberry Pi sends confimation over serial
  /*verify = Serial.readStringUntil('\n');
    verify.trim();
    Serial.println(verify);
  */
}
void loop() {
  
}
