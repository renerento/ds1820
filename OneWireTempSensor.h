/*
  OneWireTempSensor.cpp - A library for obtaining temperature data from a set of 
                          DS18x20 One-Wire temperature sensors.
                          
  Copyright (c) 2009 Jeff Kravitz

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef OneWireTempSensor_h
#define OneWireTempSensor_h

#include <../OneWire/OneWire.h>
#include <WProgram.h>

#define MAXDEVS  8        // maximum number of Temp Sensors supported
#define ADRSIZE  8        // size of DS1820 addresses



class OneWireTempSensor : public OneWire {
 private :
    /* array to hold addresses of all Temp Sensor devices */
    byte addrlist[MAXDEVS*ADRSIZE];
    /* Number of devices detected */
    int addrcount;

 public:
    /* 
     * The constructor for the OneWireTempSensor class
     * Params:
     * devPin    the Arduino Pin number connected to the OneWire bus
     */
    OneWireTempSensor(uint8_t devPin);
	/*
	 * This function performs a OneWire search algorithm looking for DS1820 devices and
	 * saves the resulting addresses in an internal array.  To conserve RAM, the
	 * library currently supports a maximum of 8 devices.
	 * It returns the number of devices found. 0 if no devices found.
	 */
	int getDevices();
    /*
	 * This obtains a temperature from a device specified by an index into the
	 * array of found devices, and returns it as a floating-point number in degrees Celsius.
	 * If the device number is larger than the number of devices found on the bus,
	 * it will return a very large negative value (-10000.0).
	 * Params:
	 * devnum       index of the device. Must be between 0 and (number of devices)-1
	 */
	float getTempC(int devnum);
     /*
	 * This obtains a temperature from a device specified by an index into the
	 * array of found devices, and returns it as a floating-point number in degrees Fahrenheit
	 * If the device number is larger than the number of devices found on the bus,
	 * it will return a very large negative value (-10000.0).
	 * Params:
	 * devnum       index of the device. Must be between 0 and (number of devices)-1
	 */
	float getTempF(int devnum);
	/*
	 * Returns the number of devices on the bus
	 */
	int getNDevices();
	/*
     * returns a pointer to the address for device N, which is an 
     * array of 8 binary bytes.
     * if the device number is larger than the number of devices found,
     * it will return 0;
     */
    byte *getAddress(int devnum);

};

#endif	//OneWireTempSensor.h

