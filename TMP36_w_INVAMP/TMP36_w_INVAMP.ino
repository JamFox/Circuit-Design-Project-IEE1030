/* Used the code from the link below as a base */
/* TMP36 analog temperature sensor with Arduino example code. More info: https://www.makerguides.com */

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Get a reading from the temperature sensor:
  int reading = 1023 - analogRead(A6); // Subtracting from 1023 because TMP36 output goes through an inverting amp.

  // Convert the reading into voltage:
  float voltage = reading * (5000 / 1024.0);

  // Convert the voltage into the temperature in Celsius:
  float temperature = (voltage - 500) / 100; // Dividing by 100 instead of 10 because after amplification the voltage
  // has one extra digit

  // Print reading, voltage and temperature in the Serial Monitor:
  Serial.println();
  Serial.println(reading);
  Serial.print(voltage);
  Serial.println(" mV");
  Serial.print(temperature);
  Serial.print(" \xC2\xB0"); // degree symbol
  Serial.println("C");

  delay(1000); // wait a second between readings
}
