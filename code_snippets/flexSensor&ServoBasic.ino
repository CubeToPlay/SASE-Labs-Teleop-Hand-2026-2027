/* NOTE: CURRENTLY NOT WORKING (In progress). The flex sensor seems to only 
output a value of "0." Need to check wiring and code logic. GOAL is to use the
flex sensor and bend it to make the servo rotate different amounts of degrees. */

#include <ESP32Servo.h>

Servo aurafullServo;
int servoPIN = 5;
int flexSensorPIN = 4;
int delayTime = 500;
int val = 0;
double scaleFactor = 1.0 / 180.0;

void setup() {
  Serial.begin(74880);
  aurafullServo.attach(servoPIN);
  pinMode(flexSensorPIN, INPUT);
}

void loop() {
  val = analogRead(flexSensorPIN);
  Serial.print("Degrees: "); 
  Serial.println(val); 


  Serial.println("ROTATING");
  aurafullServo.write(val); // sets the servo position (valid values are 0 to 108)
  delay(delayTime);

  /*
  Serial.println("ROTATING");
  aurafullServo.write(180); // sets the servo position (valid values are 0 to 108)
  delay(delayTime);
  */
}