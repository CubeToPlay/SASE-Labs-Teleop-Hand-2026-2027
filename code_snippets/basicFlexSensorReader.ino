//Basic code for reading flex sensor values 
float val = 0;
float alpha = 0.8;

void setup() {
  Serial.begin(74880);
  pinMode(4, OUTPUT);
}

void loop() {
  val = alpha * val + (1 - alpha) * analogRead(4);
  Serial.println(val / 2048); delay(500);
} 
/* May want to divide or multiply analogRead(OUTPUT_PIN#) 
by a certain value to get corresponding voltage readings from the voltage divider. */
