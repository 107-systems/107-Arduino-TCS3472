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
                               uint8_t const i2c_slave_addr)
: _error{TCS3472::Error::None}
, _io{write, read, i2c_slave_addr}
{
}


/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

bool ArduinoTCS3472::begin()
{
  /* Check the CHIP ID if it matches the expected value.
   */
  if (_io.read((Register const)((uint8_t)(TCS3472::Register::TCS3472_ID)|0x80)) != TCS3472::ID_EXPECTED_ID) {
    _error = TCS3472::Error::ChipId;
    return false;
  }

  _io.write((Register const)((uint8_t)(TCS3472::Register::TCS3472_WTIME)|0x80), 0xFF);   /* set WTIME to default value */
  _io.write((Register const)((uint8_t)(TCS3472::Register::TCS3472_ATIME)|0x80), 0xFF);   /* set ATIME to default value */
  _io.write((Register const)((uint8_t)(TCS3472::Register::TCS3472_ENABLE)|0x80), 0x0B);   /* set WEN, PEN, AEN and PON bit in ENABLE */

  return true;
}


void ArduinoTCS3472::get_colorData(struct colorDataRaw * color)
{
  color->clear = _io.read16((Register const)((uint8_t)(TCS3472::Register::TCS3472_CDATAL)|0xA0));
  color->red   = _io.read16((Register const)((uint8_t)(TCS3472::Register::TCS3472_RDATAL)|0xA0));
  color->green = _io.read16((Register const)((uint8_t)(TCS3472::Register::TCS3472_GDATAL)|0xA0));
  color->blue  = _io.read16((Register const)((uint8_t)(TCS3472::Register::TCS3472_BDATAL)|0xA0));
}

TCS3472::Error ArduinoTCS3472::error()
{
  return _error;
}
