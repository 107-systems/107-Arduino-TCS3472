/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2022 LXRobotics.
 * Author: Bernhard Mayer <bernhard@generationmake.de>
 * Contributors: https://github.com/107-systems/107-Arduino-TCS3472/graphs/contributors.
 */

#ifndef ARDUINO_TCS3472_TCS3472_IO_H_
#define ARDUINO_TCS3472_TCS3472_IO_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#undef max
#undef min
#include <functional>

#include "TCS3472_Const.h"

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace TCS3472
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

typedef std::function<void(uint8_t const, uint8_t const, uint8_t const *, uint8_t const)> I2cWriteFunc;
typedef std::function<void(uint8_t const, uint8_t const, uint8_t       *, uint8_t const)> I2cReadFunc;

/**************************************************************************************
 * CLASS DECLARATION
 **************************************************************************************/

class TCS3472_Io
{
public:

  TCS3472_Io(I2cWriteFunc write, I2cReadFunc read, uint8_t const i2c_slave_addr);


  void    write   (Register const reg);
  uint8_t read    (Register const reg);
  uint16_t read16 (Register const reg);
  void    write   (Register const reg, uint8_t const val);
  void    read    (Register const reg, uint8_t * buf, size_t const bytes);
  void    write   (Register const reg, uint8_t const * buf, size_t const bytes);


private:

  I2cWriteFunc _write;
  I2cReadFunc _read;

  uint8_t const _i2c_slave_addr;
};

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* TCS3472 */

#endif /* ARDUINO_TCS3472_TCS3472_IO_H_ */
