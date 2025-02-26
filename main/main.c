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
    printf("▓▓▓▓▓▓▓▓▒▒▒▒▒▒▒▒░░░░░░░ ✴ ░░░░░░░▒▒▒▒▒▒▒▒▓▓▓▓▓▓▓▓        \n");
    printf("  _   __           _                    \n");
    printf(" | \\ | |  ____   | |                   \n");
    printf(" |  \\| | / _` | |_ _|  _   __  ___   ______     \n");
    printf(" | |\\  || (_| |  | |  | | | | | ,_) / /__//     \n");
    printf(" |_| \\_|\\__,_|  |_|  \_\_/_/ |_|   \ \___/     \n");
    printf("                                                \n");
    printf("     ___     _     _    _   _ _   _ ___ _______  \n"); 
    printf("  ///   \\  ______     _____      ____   ____       _ _    _ ___ ___    \n");
    printf("   \\\\    / /  \ \   \\ \\ |   //__ \\ //__ \\         \\ |  | | | |_ _/ _ \\   \n");
    printf("  ___\\\\  \ \    __  \ _ \\ |  | | | | | | | |           \\|  | | | || | (_) |  \n");
    printf(" [___/___/  \_\__/_/   \\_\\|_| |_| |_| |_| |_|          \\_| \\___/ |___\\___/   \n");
    printf("                                                                      \n");



    uint8_t data[2];
    i2c_master_bus_handle_t bus_handle;
    i2c_master_dev_handle_t dev_handle;
    i2c_master_init(&bus_handle, &dev_handle);
    ESP_LOGI(TAG, "I2C initialized successfully");


    /* Demonstrate writing by resetting the MPU9250 */
    ESP_ERROR_CHECK(SHT_WRITE(dev_handle, SHT31_I2C_WRITE_ADDR, SHT31_CMD_PERIODIC_HALF_M));

    ESP_ERROR_CHECK(i2c_master_bus_rm_device(dev_handle));
    ESP_ERROR_CHECK(i2c_del_master_bus(bus_handle));
    ESP_LOGI(TAG, "I2C de-initialized successfully");



    // calling function:
    if (xTaskCreate(my_task, "SHT31_TASK", 2048, NULL, 5, NULL) != pdPASS) {
        ESP_LOGE("MAIN", "failed to create sht31 task");


    }

}
