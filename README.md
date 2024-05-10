# DGS & DGS2 Gas Sensor Module
by SPEC Sensors, a division of Interlink Electronics

## Description
This sketch reads data from a SPEC Sensors DGS or DGS2 gas sensor module and communicates the data to a computer through an Arduino device.

The DGS & DGS2 are 3.3V modules and are not compatible with 5V power supply or 5V TX/RX connections.

The example sketch is tested with Arduino MKRZERO

## DGS & DGS2 pin# : Arduino pin
1. : N/C
2. : Serial1 Receive, RXD (3V3)
3. : Serial1 Transmit, TXD (3V3)
4. : N/C
5. : N/C
6. : GND
7. : N/C
8. : 3.3V


## Commands for DGS2:
* \r [return] to perform single reading
* B to set barcode
* M to set module barcode
* P to set potentiostat settings
* O to set open circuit
* Z to set zero
* S to set sensor sensitivity
* G to perform span at a known PPM value
* N to set temperature compensation factor
* A to set ADC Average Window
* T to set temperature offset
* H to set humidity offset
* C to set toggle/untoggle continuous 1s output (supersedes DGS_Read_Interval_In_Seconds)
* L to toggle legacy DGS output
* e to read EEPROM
* h to display column header
* s to sleep module
* r to reset module

## Commands for DGS (25JAN22 or newer):
* \r [return] to perform single reading
* B to set barcode
* L to set potentiostat settings
* O to set open circuit
* Z to set zero
* S to set sensor sensitivity
* G to perform span at a known PPM value
* N to set temperature compensation factor
* A to set ADC Average Window
* T to set temperature offset
* H to set humidity offset
* C or c to set toggle/untoggle continuous 1s output (supersedes DGS_Read_Interval_In_Seconds)
* e to read EEPROM
* s to sleep module
* R or r to reset module




