/**
 * @brief Basic example demonstrating usage of 107-Arduino-TCS3472 library.
 */

/**************************************************************************************
 * INCLUDE
 **************************************************************************************/

#include <Wire.h>

#include <107-Arduino-TCS3472.h>

/**************************************************************************************
 * FUNCTION DECLARATION
 **************************************************************************************/

void i2c_generic_write(uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t const * buf, uint8_t const num_bytes);
void i2c_generic_read (uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t       * buf, uint8_t const num_bytes);

/**************************************************************************************
 * GLOBAL VARIABLES
 **************************************************************************************/

ArduinoTCS3472 tcs3472(i2c_generic_write,
                       i2c_generic_read,
                       TCS3472::DEFAULT_I2C_ADDR);

/**************************************************************************************
 * SETUP/LOOP
 **************************************************************************************/

void setup()
{
  Serial.begin(9600);
  while(!Serial) { }

  /* Setup Wire access */
  Wire.begin();

  /* Configure TSL2550 with Extended Range */
  if (!tcs3472.begin())
  {
    Serial.print("ArduinoTCS3472::begin(...) failed, error code ");
    Serial.print(static_cast<int>(tcs3472.error()));
    for(;;) { }
  }

  Serial.println("TCS3472 OK");
}

void loop()
{
  ArduinoTCS3472::colorDataRaw color;

  tcs3472.get_colorData(&color);
  Serial.print("Clear = ");
  Serial.println(color.clear);
  Serial.print("Red   = ");
  Serial.println(color.red);
  Serial.print("Green = ");
  Serial.println(color.green);
  Serial.print("Blue  = ");
  Serial.println(color.blue);
  Serial.println("");

  delay(500);
}

/**************************************************************************************
 * FUNCTION DEFINITION
 **************************************************************************************/

void i2c_generic_write(uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t const * buf, uint8_t const num_bytes)
{
  Wire.beginTransmission(i2c_slave_addr);
  Wire.write(reg_addr);
  for(uint8_t bytes_written = 0; bytes_written < num_bytes; bytes_written++) {
    Wire.write(buf[bytes_written]);
  }
  Wire.endTransmission();
}

void i2c_generic_read(uint8_t const i2c_slave_addr, uint8_t const reg_addr, uint8_t * buf, uint8_t const num_bytes)
{
  Wire.beginTransmission(i2c_slave_addr);
  Wire.write(reg_addr);
  Wire.endTransmission();

  Wire.requestFrom(i2c_slave_addr, num_bytes);
  for(uint8_t bytes_read = 0; (bytes_read < num_bytes) && Wire.available(); bytes_read++) {
    buf[bytes_read] = Wire.read();
  }
}
