#include <Wire.h>
#include <Adafruit_TMP117.h>
#include <Adafruit_Sensor.h>

Adafruit_TMP117  tmp117;
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

}

void temperature() {
  float f = 0;
  while (f < 95) {
    sensors_event_t temp; // create an empty event to be filled
    tmp117.getEvent(&temp); //fill the empty event object with the current measurements
    f = ((temp.temperature) * 1.8 ) + 32;
  }
  delay(5000);
  sensors_event_t reading; // create an empty event to be filled
  tmp117.getEvent(&reading);
  f = ((reading.temperature) * 1.8 ) + 32;
  if (f >= 95) {
    //Serial.print("Temperature  ");
    Serial.println(f);
    //Serial.print(" F");
    //Serial.println(" degrees F");
    //Serial.println("");
    delay(10000);
  }
  else{
    delay (100);
  }


}
void loop() {
  temperature();
}
