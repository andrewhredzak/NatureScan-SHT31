#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "SHT31.h"  
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static const char *TAG = "MAIN APP";





void app_main(void){


    ESP_LOGI(TAG, "START NATURE SCAN");
    printf("successful flash and build!! \n");
    printf("▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░░ ✴ ░░░░░░░▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓                        \n");
    printf("  _   __           _    ✴    ✴   ✴   ✴                                 \n");
    printf(" | \\ | |  ____   | |     ✴   ✴  ✴ ✴  ✴   ✴                           \n");
    printf(" |  \\| | / _` | |_ _|  _   __  ___   _____                               \n");
    printf(" | |\\  || (_| |  | |  | | | | | ,_) / /__//                              \n");
    printf(" |_| \\_|\\__,_|  |_|  \_\_/_/ |_|   \ \___/                              \n");
    printf("                                                                          \n");
    printf("     ___     _     _    _   _ _   _ ___ _______                           \n"); 
    printf("  ///   \\  ______     _____      ____   ____       _ _    _ ___ ___      \n");
    printf("   \\\\    / /  \ \   \\ \\ |   //__ \\ //__ \\   _____  ___              \n");
    printf("  ___\\\\  \ \    __  \ _ \\ |  | | | | | | | |  / /__// | ,_)            \n");
    printf(" [___/___/  \_\__/_/   \\_\\|_| |_| |_| |_| |_|  \ \___/ |_|              \n");
    printf("                                                                          \n");



    //uint8_t data[2];
    i2c_master_bus_handle_t bus_handle;
    i2c_master_dev_handle_t dev_handle;
    i2c_master_init(&bus_handle, &dev_handle);
    float temperature, humidity;
    ESP_LOGI(TAG, "I2C initialized successfully");




   // Probe the sensor to check if it is connected to the bus with a 10ms timeout
    esp_err_t err = i2c_master_probe(bus_handle, SHT31_I2C_ADDR_0X44, 200);

    if(err == ESP_OK) {
        ESP_LOGI(TAG, "SHT31 sensor found");
        //xTaskCreate(sht4x_read_task, "sht4x_read_task", 4096, NULL, 5, NULL);
    } else {
        ESP_LOGE(TAG, "SHT31 sensor not found");
        //sht4x_device_delete(sht4x_handle);
    }



    /* Demonstrate writing by resetting the MPU9250 */
    ESP_ERROR_CHECK(SHT_START(dev_handle, SHT31_CMD_PERIODIC_MSB_TWO, SHT31_CMD_PERIODIC_LSB_HIGH));
    vTaskDelay(1000 / portTICK_PERIOD_MS);

    ESP_ERROR_CHECK(SHT_READ(dev_handle, &temperature, &humidity ));

    ESP_ERROR_CHECK(i2c_master_bus_rm_device(dev_handle));
    ESP_ERROR_CHECK(i2c_del_master_bus(bus_handle));
    ESP_LOGI(TAG, "I2C de-initialized successfully");



    // calling function:
    if (xTaskCreate(my_task, "SHT31_TASK", 2048, NULL, 5, NULL) != pdPASS) {
        ESP_LOGE("MAIN", "failed to create sht31 task");


    }

}
