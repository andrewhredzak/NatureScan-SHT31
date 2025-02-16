
#include "SHT31.h"
#include <string.h>     // For memset if needed
#include <stdio.h>      // For debug printing (optional)
#include "SHT31.h"
#include "esp_mac.h"
#include "esp_log.h"
#include "freertos/task.h"



// Define the commands for the SHT31 sensor
#define SHT31_CMD_READ_STATUS 0xF32D
#define SHT31_CMD_CLEAR_STATUS 0x3041
#define SHT31_CMD_SOFT_RESET 0x30A2
#define SHT31_CMD_HEATER_EN 0x306D
#define SHT31_CMD_HEATER_DIS 0x3066
#define SHT31_CMD_MEAS_PERI_H_M 0x2130 // 1 mps, medium repeatability


static const char *TAG = "SHT31C";

// prediction: wrapping i2c driver command [i2c_master_transmit_receive]
// and then calling it in main


/*
sets up variables
calls function 
stores data 
calculates temp and humidity
write to console 
*/



void my_task(void *pvParameters){
    while(1){
        printf("first function in sht, HI!  \n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
        
}





