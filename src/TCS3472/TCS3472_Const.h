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
  TCS3472_PowerDownState            = 0x00,
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

static uint8_t constexpr ID_EXPECTED_ID = 0x03;
static uint8_t constexpr DEFAULT_I2C_ADDR = 0x39;

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
