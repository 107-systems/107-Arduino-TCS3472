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

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class ArduinoTCS3472
{

public:

  struct colorDataRaw{
                 uint16_t clear;
                 uint16_t red;
                 uint16_t green;
                 uint16_t blue;
                    };


  ArduinoTCS3472(TCS3472::I2cWriteFunc write,
                 TCS3472::I2cReadFunc read,
                 uint8_t const i2c_slave_addr);

  bool begin();
  void get_colorData(struct colorDataRaw * color);

  TCS3472::Error error();

private:

  TCS3472::Error _error;
  TCS3472::TCS3472_Io _io;

};

#endif /* _107_ARDUINO_TCS3472_H_ */
