/*

DGS/DGS2 Gas Sensor Module
SPEC Sensors is a division of Interlink Electronics

This sketch reads data from a SPEC Sensors DGS or DGS2 gas sensor module 
and communicates the data to a computer. 

The DGS & DGS2 are 3.3V modules and are not compatible with 5V power supply or 5V TX/RX connections.

DGS & DGS2 pin# : Arduino pin
              1 : N/C
              2 : Serial1 Receive, RXD (3V3)
              3 : Serial1 Transmit, TXD (3V3)
              4 : N/C
              5 : N/C
              6 : GND
              7 : N/C
              8 : 3.3V

This sketch is tested with Arduino MKRZERO

created 6 MAY 2024
by Gavin O'Toole
Interlink Electronics

*/

#include <arduino-timer.h> //https://github.com/contrem/arduino-timer

//#define Continous_DGS_Output            // *** Uncomment to enable streaming output ***
#define DGS_Read_Interval_In_Seconds 5  // *** Modify this to change continous output interval ***

// Create a timer with default settings
auto timer = timer_create_default(); 

// Query a DGS measurement on Serial1
bool Read_DGS(void *) 
{
  Serial1.write('\r');
  return true;
}

bool Initial_DGS_Read(void *) 
{
  Serial1.print('\r');
  return false;
}

void setup() 
{
  Serial.begin(9600);   //Start Serial for USB terminal comm 
  while(!Serial);
  Serial1.begin(9600);  //Start Serial1 for DGS comm
  delay(1000);

  Serial.print('\r');
  Serial.println("*******************DGS/DGS2 Gas Sensor Module*******************");
  Serial.println("*******SPEC Sensors is a division of Interlink Electronics******");

  // Query eeprom settings from DGS/DGS2
  Serial1.write('e');
  delay(200);

  // Query header string from DGS2 (this command is recognized by DGS2. It is not recognized by DGS)
  Serial1.write('h');  
  delay(200);

  
#ifdef Continous_DGS_Output // User timer to query DGS/DGS2 for measurement string at a regular interval (can interfere with some commands ex: S)
  timer.every((DGS_Read_Interval_In_Seconds * 1000) , Read_DGS); // Starts streaming output 
#else // Initial Reading From DGS/DGS2
  timer.in(1000, Initial_DGS_Read);
#endif
}

void loop() 
{
  // While data is available from DGS/DGS2 serial, read it and print result to USB terminal
  while (Serial1.available() > 0) 
  {
    Serial.write(Serial1.read());
    yield();
  }
  
  // While data (command) is available from USB terminal, read it and write it to DGS/DGS2 
  while (Serial.available() > 0) 
  {
    Serial1.write(Serial.read());
    yield();
  }

  timer.tick(); 
}
