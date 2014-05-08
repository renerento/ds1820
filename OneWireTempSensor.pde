/*
 OneWireTempSensor.pde - A example for obtaining temperature
 values from a set of attached DS18S20 temp sensors
 Copyright (c) 2009 Jeff Kravitz

 2014-May-05 included lcd-part and removed serial-implementation. Also included Celsius-convert. This code is made with Arduino 0022
 DS1820 in connected to pin 12.
 Rene Rento Contact: renerento@gmail.com

 This program is free software; you can redistribute it and/or
 modify it under the terms of the GNU General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 General Public License for more details.
 You should have received a copy of the GNU General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

 #include <OneWire.h>
 #include <OneWireTempSensor.h>
 #include <LiquidCrystal.h>
 // LCD=======================================================
 //initialize the library with the numbers of the interface pins
 LiquidCrystal lcd(13, 11, 5, 4, 1, 0);
 #define LCD_WIDTH 40
 #define LCD_HEIGHT 2
 OneWireTempSensor sensors(12); // the OneWireTempSensor object
 int numdevs; // number of devices

 /*************************************************************/
 /* Main Code Start here */
 /*************************************************************/
 void setup() { lcd.begin(LCD_WIDTH, LCD_HEIGHT,1);
 lcd.setCursor(0,0);
 lcd.print("DS1820 Test");
 delay(1000);
 lcd.clear();
 numdevs = sensors.getDevices(); // this searches for all DS1820 devices on the OneWire bus
 } 
 void loop() {
 int currdev;
 float real_temp;
 int temp;
 int aste;

 // loop through all the DS1820 temp sensors on the bus
 for (currdev = 0; currdev < numdevs; ++currdev) {
 /* get the temperature */
 real_temp = sensors.getTempF(currdev);
 temp = (int) real_temp;
 aste = (5.0/9.0) * (temp-32);
 lcd.setCursor(0,0);
 lcd.print(aste);
 }
 }
