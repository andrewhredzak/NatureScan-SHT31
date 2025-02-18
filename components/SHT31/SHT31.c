#include <stdio.h>
#include "sht31.h"
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"








void my_task(void *pvParameters) {
    while (1) {
        ESP_LOGI("SHT31_TASK", "the task is running!");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}