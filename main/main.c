#include <stdio.h>
#include "esp_log.h"
#include "driver/i2c_master.h"

#include <string.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "SHT31.h" 
#include "esp_mac.h"


#define SCL_IO_PIN CONFIG_I2C_MASTER_SCL
#define SDA_IO_PIN CONFIG_I2C_MASTER_SDA
#define MASTER_FREQUENCY CONFIG_I2C_MASTER_FREQUENCY
#define PORT_NUMBER -1

static const char *TAG = "MAIN_APP";



typedef struct {
    i2c_master_bus_handle_t bus_handle;
    i2c_master_dev_handle_t dev_handle;
} i2c_handles_t;


static i2c_handles_t i2c_handles; // Declare the struct statically



// Init function for ESP-IDF I2C master
static void i2c_master_dev_init(void)
{
    i2c_master_bus_config_t i2c_mst_config = {
        .clk_source = I2C_CLK_SRC_DEFAULT,
        .i2c_port = PORT_NUMBER,
        .scl_io_num = SCL_IO_PIN,
        .sda_io_num = SDA_IO_PIN,
        .glitch_ignore_cnt = 7,
        .flags.enable_internal_pullup = true,
    };


// I2C bus initialization is done in two parts: first, initialization of the bus with 
// i2c_new_master_bus(), 
// then, initialization of the I2C device with 
// i2c_master_bus_add_device().


i2c_master_bus_handle_t bus_handle;
ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));


ESP_LOGD(TAG, "Value of SHT31_I2C_ADDR_0X44: %d", SHT31_I2C_ADDR_0X44);

i2c_device_config_t dev_cfg = {
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = SHT31_I2C_ADDR_0X44,
    .scl_speed_hz = 100000,
};


// then, initialization of the I2C device with 
// i2c_master_bus_add_device().

i2c_master_dev_handle_t dev_handle;
ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &dev_cfg, &dev_handle));

}






// main entry point 
void app_main(void)
{
    ESP_LOGI(TAG, "Starting main");
    printf("successful build and flash!!\n");
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






    // Initialize I2C
    i2c_master_dev_init();

    
    
   // Add the I2C device

   xTaskCreate(my_task, "my_task", 2048, NULL, 5, NULL);







    
}












