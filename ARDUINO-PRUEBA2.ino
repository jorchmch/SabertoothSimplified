
// Simple Example Sample
// Copyright (c) 2012 Dimension Engineering LLC
// See license.txt for license details.

#include <SabertoothSimplified.h>
#include <SoftwareSerial.h>
SoftwareSerial SWSerial(NOT_A_PIN, 11);  //TX ES  PIN 11

SabertoothSimplified ST(SWSerial); 
                         // For how to configure the Sabertooth, see the DIP Switch Wizard for
                         //   http://www.dimensionengineering.com/datasheets/SabertoothDIPWizard/start.htm
                         // Be sure to select Simplified Serial Mode for use with this library.
                         // This sample uses a baud rate of 9600.
                         //
                         // Connections to make:
                         //   Arduino TX->1  ->  Sabertooth S1
                         //   Arduino GND    ->  Sabertooth 0V
                         //   Arduino VIN    ->  Sabertooth 5V (OPTIONAL, if you want the Sabertooth to power the Arduino)
                         //
                         // If you want to use a pin other than TX->1, see the SoftwareSerial example.
                                        
void setup()
{
  Serial.begin(9600);
  SWSerial.begin(9600); // This is the baud rate you chose with the DIP switches.
}


void loop()
{
  int power;
  int DUR=30;
  // -127 ES FULL REVERSA, 127 FULL DEFRENTE
  // 20ms delay  para cada cambio 
  for (power = -127; power <= 127; power ++)
  {
    ST.motor(1, power);
    ST.motor(2, power);
    delay(DUR);
    Serial.println(power);
  }
  Serial.println(power);
  // Now go back the way we came.
  for (power = 127; power >= -127; power --)
  {
    ST.motor(1, power);
    ST.motor(2, power);
    delay(DUR);
    Serial.println(power);
  }
}
