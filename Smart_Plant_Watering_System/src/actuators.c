/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "../include/watering_logic.h"
#include "../include/actuators.h"

/**********************************************************************************************************************
* Global variable
*********************************************************************************************************************/

/**********************************************************************************************************************
* Function definition
*********************************************************************************************************************/

/******************************************************************************************************************//**
 * If the system is in MODE_AUTO
        Compare the current soil moisture to the minimum watering threshold.
        If the moisture is too low and the time between waterings has expired, activate the pump.
        While the pump is running, continue to monitor the moisture and stop the pump when the maximum threshold is
        reached or the maximum watering time has expired.
 *********************************************************************************************************************/
system_setting_t auto_logic_control(sensor_data_setting_t sensor_data, system_setting_t system_setting)
{
    /* Check if the system is in MODE_AUTO */
    if (system_setting.current_mode == MODE_AUTO)
    {
        /* Check if the moisture is too low and the time between waterings has expired */
        if ((system_setting.moisture_threshold_min > sensor_data.soil_moisture) && (system_setting.water_time_max == 0))
        {
            /* Activate the pump. */
            system_setting.pump_status = turn_pump_on();

            /* Update led status */
            system_setting.led_status = LED_LOW_MOISTURE_ALERT;
        }

        /* While the pump is running check if the maximum threshold is reached or the maximum watering time has expired */
        if ((system_setting.pump_status == PUMP_ON) 
            && (sensor_data.soil_moisture > system_setting.moisture_threshold_max)
            && (system_setting.water_time_max == 0))
        {
            /* Stop the pump */
            system_setting.pump_status = turn_pump_off();
        }
    }

    return system_setting;
}