#define LXCONST 1.5 /* A value calculated by analysing a Reverse Light Current vs. Illuminance
graph from BPW34 Datasheet

ex. Program shows that the input voltage is around 150mV According to Ohms Law Vout = Rf * Ip, 
150mV = 100000Ω * Ip, Ip = 15µA. 
At 15µA the illuminance should be around 220 lx. Therefore the input voltage sholud
be multiplied by 1.5 (≈ 220 / 150) */

void setup() {
  // Begin serial communication at a baud rate of 9600:
  Serial.begin(9600);
}

void loop() {
  // Get a reading from the photodiode
  int reading = analogRead(A6);

  // Convert the reading into voltage:
  float voltage = reading * (5000 / 1024.0);

  float lux = LXCONST * voltage;

  // Print reading in the Serial Monitor
  Serial.println();
  Serial.println(reading);
  Serial.print(voltage);
  Serial.println(" mV");
  Serial.print(lux);
  Serial.println(" lux");

  delay(1000); // wait one second between readings

}
