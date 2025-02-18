#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c_master.h"
#include "SHT31.h"  
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"





void app_main(void){

    printf("successful flash and build!!\n");
    printf("  _   __           _                    \n");
    printf(" | \\ | |  ____   | |                   \n");
    printf(" |  \\| | / _` | |_ _|  _   __  ___   ______     \n");
    printf(" | |\\  || (_| |  | |  | | | | | ,_) / /__//     \n");
    printf(" |_| \\_|\\__,_|  |_|  \_\_/_/ |_|   \ \___/     \n");
    printf("                                                \n");
    printf("     ___     _     _    _   _ _   _ ___ _______  \n");
    printf("  ///   \\    ______      _    _   _ _    _ ___ ___  \n");
    printf("   \\\\     / /   \ \   \\   | \\ |  | | | |_ _/ _ \\ \n");
    printf("  ___\\\\   \ \        \ _ \\ |  \\|  | | | || | (_) |\n");
    printf(" [___/___/   \_\___//  \\_\\|_|\\_| \\___/ |___\\___/ \n");


    // calling function:
    if (xTaskCreate(my_task, "SHT31_TASK", 2048, NULL, 5, NULL) != pdPASS) {
        ESP_LOGE("MAIN", "failed to create sht31 task");


    }

}
