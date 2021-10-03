void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Get a reading from the photodiode
  int reading = 1023 - analogRead(A6);

  // Convert the reading into voltage:
  float voltage = reading * (5000 / 1024.0);

  // Print reading in the Serial Monitor
  Serial.println(reading);
  Serial.println(voltage);

  delay(1000); // wait one second between readings

}
