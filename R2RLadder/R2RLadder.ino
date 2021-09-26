// 8 bits of resolution is 0-255
#define RESOLUTION 255

void setup() {
  // Init Uno at 9600 baud
  Serial.begin(9600);
  // Port D at Arduino Uno (pin 0-7), (1=out, 0=in)
  DDRD = B11111111;  
}

void loop() {
  // Drawing sine from 0 to 360 degrees
  for (int i = 0; i < 360; i++) { 
    PORTD = ((sin(i * DEG_TO_RAD) + 1) * RESOLUTION) / 2; 
    delay(10); 
    // Read the output of the DAC
    Serial.println(analogRead(A0)); 
  }
}
