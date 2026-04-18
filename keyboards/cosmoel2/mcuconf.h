#pragma once
#include_next <mcuconf.h>

// Set up SPI
#undef RP_SPI_USE_SPI1
#define RP_SPI_USE_SPI1 TRUE

// Set up I2C for azoteq trackpad
#undef RP_I2C_USE_I2C1
#define RP_I2C_USE_I2C1 TRUE
