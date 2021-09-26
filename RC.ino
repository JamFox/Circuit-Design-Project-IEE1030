// Define resolution of PWM pin...
// ...between 0 (always off) and 255 (always on)
// 8 bits of resolution
#define RESOLUTION 255 

// Define variable for selecting the pin
// Using D9 PWM pin here
int pulsePin = 9;

void setup()
{
  Serial.begin(9600);
  // Set our PWM pin as output
  pinMode(pulsePin, OUTPUT);
}

void loop()
{
  // Calculate value between 0 and RESOLUTION for a sine wave
  for (int i = 0; i < 360; i++) {
  analogWrite(pulsePin,((sin(i * DEG_TO_RAD) + 1) * RESOLUTION) / 2);
  // Print analog reading to Serial
  Serial.println(analogRead(A0));
  delay(10);
  }
}
