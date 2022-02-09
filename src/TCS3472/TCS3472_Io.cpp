/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2022 LXRobotics.
 * Author: Bernhard Mayer <bernhard@generationmake.de>
 * Contributors: https://github.com/107-systems/107-Arduino-TCS3472/graphs/contributors.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include "TCS3472_Io.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace TCS3472
{

/**************************************************************************************
 * CTOR/DTOR
 **************************************************************************************/

TCS3472_Io::TCS3472_Io(I2cWriteFunc write, I2cReadFunc read, uint8_t const i2c_slave_addr)
: _write{write}
, _read{read}
, _i2c_slave_addr{i2c_slave_addr}
{

}

/**************************************************************************************
 * PUBLIC MEMBER FUNCTIONS
 **************************************************************************************/

uint8_t TCS3472_Io::read(Register const reg)
{
  uint8_t data = 0;
  read(reg, &data, 1);
  return data;
}

uint16_t TCS3472_Io::read16(Register const reg)
{
  uint16_t data = 0;
  read(reg, (uint8_t *)&data, 2);
  return data;
}

void TCS3472_Io::write(Register const reg)
{
  uint8_t const val=0;
  write(reg, &val, 0);
}

void TCS3472_Io::write(Register const reg, uint8_t const val)
{
  write(reg, &val, 1);
}

void TCS3472_Io::read(Register const reg, uint8_t * buf, size_t const bytes)
{
  _read(_i2c_slave_addr, to_integer(reg), buf, bytes);
}

void TCS3472_Io::write(Register const reg, uint8_t const * buf, size_t const bytes)
{
  _write(_i2c_slave_addr, to_integer(reg), buf, bytes);
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* TCS3472 */
