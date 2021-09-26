// Library from https://github.com/SteveGdvs/MCP48xx/
#include <MCP48xx.h> 

// MCP4802 has resolution of 8 bits
#define RESOLUTION 255 

const byte mcp4802_cs_pin = 10; // Set CS to Digital pin 10 (SS)
const byte mcp4802_ldac_pin = 9; // Set LDAC to Digital pin 9
MCP4802 dac(mcp4802_cs_pin); // Define the MCP4802 instance

void setup() {
  Serial.begin(9600);

  // Set LDAC to LOW since its tied to GND
  pinMode(mcp4802_ldac_pin, OUTPUT);
  digitalWrite(mcp4802_ldac_pin, LOW);
  
  // Call the init() method to initialize the instance
  dac.init();
  //The  devices  have  a  high  precision  internal  voltage reference 
  //(VREF = 2.048V)
  //Configure the full-scale range of the device to be 2.048V or 4.096V.
  // Gain Selection Option bit (gain of 1 of 2).
  dac.setGainA(MCP4802::High);
  dac.setGainB(MCP4802::High);
  // Turn on both channels
  dac.turnOnChannelA();
  dac.turnOnChannelB();
  // Set both channels to 0 initially
  dac.setVoltageA(0);
  dac.setVoltageB(0);
  // Send set values to the DAC
  dac.updateDAC();
}

void loop() {
  for (int i = 0; i < 360; i++) {
    // Calculate value between 0 and RESOLUTION for a sine wave
    dac.setVoltageA(((sin(i * DEG_TO_RAD) + 1) * RESOLUTION) / 2);
    dac.setVoltageB(((sin(i * DEG_TO_RAD) + 1) * RESOLUTION) / 2);
    dac.updateDAC();
    // Print analog reading to Serial
    Serial.println(analogRead(A0));
    delay(10);
  }
}
