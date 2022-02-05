/**
 * This software is distributed under the terms of the MIT License.
 * Copyright (c) 2022 LXRobotics.
 * Author: Bernhard Mayer <bernhard@generationmake.de>
 * Contributors: https://github.com/107-systems/107-Arduino-TCS3472/graphs/contributors.
 */

#ifndef ARDUINO_TCS3472_TCS3472_CONST_H_
#define ARDUINO_TCS3472_TCS3472_CONST_H_

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <stdint.h>

#include <type_traits>

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

namespace TCS3472
{

/**************************************************************************************
 * TYPEDEF
 **************************************************************************************/

enum class Register : uint8_t
{
  TCS3472_ENABLE            = 0x00,
  TCS3472_ATIME             = 0x01,
  TCS3472_WTIME             = 0x03,
  TCS3472_AILTL             = 0x04,
  TCS3472_AILTH             = 0x05,
  TCS3472_AIHTL             = 0x06,
  TCS3472_AIHTH             = 0x07,
  TCS3472_PERS              = 0x0C,
  TCS3472_CONFIG            = 0x0D,
  TCS3472_CONTROL           = 0x0F,
  TCS3472_ID                = 0x12,
  TCS3472_STATUS            = 0x13,
  TCS3472_CDATAL            = 0x14,
  TCS3472_CDATAH            = 0x15,
  TCS3472_RDATAL            = 0x16,
  TCS3472_RDATAH            = 0x17,
  TCS3472_GDATAL            = 0x18,
  TCS3472_GDATAH            = 0x19,
  TCS3472_BDATAL            = 0x1A,
  TCS3472_BDATAH            = 0x1B,
};

enum class Error : int
{
  None    =  0,
  Timeout = -1,
  ChipId  = -2,
  Param   = -3,
};

/**************************************************************************************
 * CONSTANTS
 **************************************************************************************/

static uint8_t constexpr ID_EXPECTED_ID = 0x44;
static uint8_t constexpr DEFAULT_I2C_ADDR = 0x29;

/**************************************************************************************
 * CONVERSION FUNCTIONS
 **************************************************************************************/

template <typename Enumeration>
constexpr auto to_integer(Enumeration const value) -> typename std::underlying_type<Enumeration>::type
{
  return static_cast<typename std::underlying_type<Enumeration>::type>(value);
}

template <typename Enumeration>
constexpr auto bp(Enumeration const value) -> typename std::underlying_type<Enumeration>::type
{
  return to_integer(value);
}

template <typename Enumeration>
constexpr auto bm(Enumeration const value) -> typename std::underlying_type<Enumeration>::type
{
  return (1 << to_integer(value));
}

/**************************************************************************************
 * NAMESPACE
 **************************************************************************************/

} /* TCS3472 */

#endif /* ARDUINO_TCS3472_TCS3472_CONST_H_ */
