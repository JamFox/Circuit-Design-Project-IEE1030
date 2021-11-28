/*
  74HC165 Shift Register Demonstration 1
  74hc165-demo.ino
  Read from 8 switches and display values on serial monitor

  DroneBot Workshop 2020
  https://dronebotworkshop.com
*/

// Define Connections to 74HC165

// PL pin 1
int load = 6;
// CE pin 15
int clockEnablePin = 5;
// Q7 pin 7
int dataIn = 4;
// CP pin 2
int clockIn = 7;

void setup()
{

  // Setup Serial Monitor
  Serial.begin(9600);

  // Setup 74HC165 connections
  pinMode(load, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockIn, OUTPUT);
  pinMode(dataIn, INPUT);
}

void loop()
{

  // Write pulse to load pin
  digitalWrite(load, LOW);
  delayMicroseconds(5);
  digitalWrite(load, HIGH);
  delayMicroseconds(5);

  // Get data from 74HC165
  digitalWrite(clockIn, HIGH);
  digitalWrite(clockEnablePin, LOW);
  byte incoming = shiftIn(dataIn, clockIn, LSBFIRST);
  digitalWrite(clockEnablePin, HIGH);

  // Print to serial monitor
  Serial.print("Pin States:\r\n");
  Serial.println(incoming, BIN);
  delay(400);
}
