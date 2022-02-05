/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2022 LXRobotics.
 * Author: Bernhard Mayer <bernhard@generationmake.de>
 * Contributors: https://github.com/107-systems/107-Arduino-TCS3472/graphs/contributors.
 */

#ifndef _107_ARDUINO_TCS3472_H_
#define _107_ARDUINO_TCS3472_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "TCS3472/TCS3472_Io.h"
#include "Arduino.h"

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoTCS3472
{

public:

  ArduinoTCS3472(TCS3472::I2cWriteFunc write,
                 TCS3472::I2cReadFunc read,
 //                TCS3472::DelayFunc delay,
                 uint8_t const i2c_slave_addr);

  bool begin(bool const use_extended);
  float get_lux();

  TCS3472::Error error();

private:

  TCS3472::Error _error;
  TCS3472::TCS3472_Io _io;

};

#endif /* _107_ARDUINO_TCS3472_H_ */
