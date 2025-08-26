#ifndef CONFIG_H
#define CONFIG_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Type definitions
 *********************************************************************************************************************/

/* System Mode */
typedef enum e_system_mode
{
    MODE_AUTO,                          // System manage watering via sensor automatically.
    MODE_MANUAL,                        // System is waiting for manual order or locked automatically.
} system_mode_t;

/* Pump watering status */
typedef enum e_pump_status
{
    PUMP_OFF,                           // Pump does not work.
    PUMP_ON,                            // Pump is working.
} pump_status_t;

/* Led status */
typedef enum e_led_status
{
    LED_NORMAL,                         // System is working normally.
    LED_WATERING,                       // System is watering.
    LED_LOW_MOISTURE_ALERT,             // Soil moisture is too low (not watered or not watered enough).
    LED_ERROR,                          // System Error (broken sensor or stucked pump)
} led_status_t;

/* Sensor data */
typedef struct st_sensor_data_setting
{
    int soil_moisture;                  // Read soil moisture data from sensor.
    int temperature_env;                // Read temperature environment from sensor.
} sensor_data_setting_t;

/* System setting */
typedef struct st_system_setting
{
    int moisture_threshold_min;         // Minimum soil moisture threshold to start watering.
    int moisture_threshold_max;         // Maximum soil moisture threshold to stop watering.
    uint8_t water_time_max;             // Maximum watering time per time.
    uint8_t sensor_check_cycle;         // Sensor checking cycle.
    system_mode_t current_mode;         // current mode of system.
    pump_status_t pump_status;          // Pump status.
    led_status_t led_status;            // Led status
} system_setting_t;

/**********************************************************************************************************************
* Global variable
*********************************************************************************************************************/

/***********************************************************************************************************************
 * Function Declaration
 **********************************************************************************************************************/


#endif /* CONFIG_H */