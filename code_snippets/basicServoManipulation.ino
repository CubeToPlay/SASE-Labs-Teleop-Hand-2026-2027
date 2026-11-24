/* Basic code for manipulating servo 
(SPECIFIC TO ESP32, NEED TO DOWNLOAD AND USE "ESP32Servo" LIBRARY) */
#include <ESP32Servo.h>

Servo aurafullServo;
int selectedPin = 5;
int delayTime = 1000;

void setup() {
  aurafullServo.attach(selectedPin); Serial.begin(74880);
}

void loop() {
  Serial.println("ROTATING");
  aurafullServo.write(180); // sets the servo position (valid values are 0 to 108)
  delay(delayTime);
  Serial.println("ROTATING");
  aurafullServo.write(0);
  delay(delayTime);
} 
/* According to the data sheet posted in the electrical channel, 
the MG996R Metal Gears Digital Servo Motor for High Speed & Torque 
RC CAR Truck Boat Racing Car Helicopter and Airplane (used with the code above) 
has a range between 0 and 180 degrees inclusive. */