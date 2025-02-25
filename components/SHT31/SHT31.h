#ifndef SHT31_H
#define SHT31_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include "driver/i2c_master.h"


#define SHT31_I2C_ADDR_0X44 0x44 // device address given from senserion 
#define SHT31_I2C_ADDR_0X45 0x45 

//#define xfer_timeout_ms 3000 // timeout-- 3 seconds



/*
 * Periodic Measurement Mode Commands:
 *   - 'MPS' => measurements per second
 *   - 'Repeatability' => High (H), Medium (M), Low (L)
 */

#define SHT31_CMD_PERIODIC_HALF_H 0x2032 
#define SHT31_CMD_PERIODIC_HALF_M 0x2024
#define SHT31_CMD_PERIODIC_HALF_L 0x202F





void my_task(void *pvParameters);

esp_err_t SHT_WRITE(i2c_master_bus_handle_t bus_handle, uint32_t address, const uint8_t *data ,uint32_t size);


/*
Parameters
i2c_dev         -- [in] I2C master device handle that created by i2c_master_bus_add_device.

write_buffer    -- [in] Data bytes to send on the I2C bus.

write_size      -- [in] Size, in bytes, of the write buffer.

xfer_timeout_ms -- [in] Wait timeout, in ms. Note: -1 means wait forever.
*/


//esp_err_t i2c_eeprom_write(i2c_eeprom_handle_t eeprom_handle, uint32_t address, const uint8_t *data, uint32_t size);



#ifdef __cplusplus
}
#endif
#endif /* SHT31_H */