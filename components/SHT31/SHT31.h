#ifndef SHT31_H
#define SHT31_H

#ifdef __cplusplus
extern "C" {
#endif



#include <stdint.h>
#include <stdbool.h>
#include "driver/i2c_master.h"


/* ============================================================================
 *  I2C ADDRESS
 * 
 *  The SHT31 sensor can be configured with two possible 7-bit addresses:
 *  - 0x44 (default if ADDR pin is connected to GND)
 *  - 0x45 (if ADDR pin is connected to VDD)
 * ============================================================================
 */
#define SHT31_I2C_ADDR_0X44   0x44
#define SHT31_I2C_ADDR_0X45   0x45

/* Use whichever address matches your hardware wiring */
#define SHT31_I2C_ADDR_DEFAULT   SHT31_I2C_ADDR_0X44

/* ============================================================================
 *  SHT31 COMMANDS
 * 
 *  Below are commonly used command codes from the Sensirion SHT3x datasheet.
 *  You can adjust or add more as needed (e.g., for heater control, clearing
 *  status, etc.).
 * ============================================================================
 */
// Soft reset command
#define SHT31_CMD_SOFT_RESET                0x30A2

// Read Status Register
#define SHT31_CMD_READ_STATUS               0xF32D

// Clear Status Register
#define SHT31_CMD_CLEAR_STATUS              0x3041

/*
 * Periodic Measurement Mode Commands:
 *   - 'MPS' => measurements per second
 *   - 'Repeatability' => High (H), Medium (M), Low (L)
 *
 * Example: 0x2236 = "0.5 MPS, High repeatability"
 *
 * Refer to datasheet for the full command set. Below are a few examples:
 */
#define SHT31_CMD_PERIODIC_HALF_H           0x2032  // 0.5 mps, high repeatability
#define SHT31_CMD_PERIODIC_HALF_M           0x2024  // 0.5 mps, medium repeatability
#define SHT31_CMD_PERIODIC_HALF_L           0x202F  // 0.5 mps, low repeatability

// Fetch data in periodic mode
#define SHT31_CMD_FETCH_DATA                0xE000

// Stop periodic mode
#define SHT31_CMD_STOP_PERIODIC             0x3093

/*
 * Single-Shot Measurement Mode Commands (for reference):
 *   - 0x2400 = High repeatability, clock stretching enabled
 *   - 0x240B = High repeatability, clock stretching disabled
 *   etc.
 */

/* ============================================================================
 *  DATA STRUCTURES
 * ============================================================================
 */

/**
 * @brief Holds measured sensor values for temperature (C) and humidity (%RH)
 */
typedef struct {
    float temperature;    ///< Temperature in Celsius
    float humidity;       ///< Relative humidity in %
} SHT31_Measurement_t;

void my_task(void *pvParameters);







#ifdef __cplusplus
}
#endif

#endif /* SHT31_H */