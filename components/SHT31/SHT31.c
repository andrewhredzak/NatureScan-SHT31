#include <stdio.h>
#include <string.h>
#include "sht31.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


static const char TAG[] = "SHT31.C";






void my_task(void *pvParameters) {
    while (1) {
        ESP_LOGI("SHT31_TASK", "the task is running!"); //this just logs stuff. calle by esp_log
        vTaskDelay(pdMS_TO_TICKS(1000));   // vtaskDelay is from FreeRTOS
    }
}





esp_err_t SHT_WRITE(i2c_master_bus_handle_t bus_handle, uint32_t address,const uint8_t *data ,uint32_t size)
{
    ESP_RETURN_ON_FALSE(bus_handle, ESP_ERR_NO_MEM, TAG, "no mem for buffer");

    return i2c_master_transmit(bus_handle->i2c_dev, eeprom_handle->buffer, eeprom_handle->addr_wordlen + size, -1);

}



