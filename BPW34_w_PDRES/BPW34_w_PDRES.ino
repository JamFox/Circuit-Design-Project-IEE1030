void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
}
void loop() {
  // Get a reading from the photodiode
  int reading = analogRead(A6);
  // Convert the reading into voltage:
  float voltage = reading * (5000 / 1024.0);
  
  float lux = 1.33333 * voltage;

  // Print reading in the Serial Monitor
  Serial.println();
  Serial.println(reading); // print reading
  Serial.print(voltage);   // print voltage
  Serial.println(" mV");
  Serial.print(lux);       // print light illuminance
  Serial.println(" lux");

  delay(1000); // wait one second between readings
}
