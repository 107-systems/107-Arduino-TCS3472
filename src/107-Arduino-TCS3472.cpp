/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2022 LXRobotics.
 * Author: Bernhard Mayer <bernhard@generationmake.de>
 * Contributors: https://github.com/107-systems/107-Arduino-TCS3472/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "107-Arduino-TCS3472.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

using namespace TCS3472;

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

ArduinoTCS3472::ArduinoTCS3472(TCS3472::I2cWriteFunc write,
                               TCS3472::I2cReadFunc read,
 //                              TCS3472::DelayFunc delay,
                               uint8_t const i2c_slave_addr)
: _error{TCS3472::Error::None}
, _io{write, read, i2c_slave_addr}
{
}


/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

bool ArduinoTCS3472::begin(bool const use_extended)
{
  /* Check the CHIP ID if it matches the expected value.
   */
  if (_io.read(TCS3472::Register::TCS3472_ID) != TCS3472::ID_EXPECTED_ID) {
    _error = TCS3472::Error::ChipId;
    return false;
  }

  _io.write(TCS3472::Register::TCS3472_WTIME, 0xFF);   /* set WTIME to default value */
  _io.write(TCS3472::Register::TCS3472_ATIME, 0xFF);   /* set ATIME to default value */
  _io.write(TCS3472::Register::TCS3472_ENABLE, 0x0B);   /* set WEN, PEN, AEN and PON bit in ENABLE */

  return true;
}


float ArduinoTCS3472::get_lux()
{
  float r=0, light_level=0;
  return light_level;
}

TCS3472::Error ArduinoTCS3472::error()
{
  return _error;
}
