/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "led_driver.h"

/**********************************************************************************************************************
 * Macro definitions
 *********************************************************************************************************************/
#define LED_MASK_BIT    0xffffff

/**********************************************************************************************************************
* Functions
*********************************************************************************************************************/

/******************************************************************************************************************//**
 * Initializes a buffer for the LED strip with the given number of pixels.
 * Returns 0 on success, -1 on failure
 *********************************************************************************************************************/
int led_init(size_t num_pixels)
{
    gp_led_strip = (uint32_t*)malloc(num_pixels * sizeof(uint32_t));

    /* Check that whether memory is allocate success or not */
    if(NULL != gp_led_strip)
    {
        printf("LED Initialize success /n");
        return 0;
    }
    else
    {
        printf("LED Initialize failure /n");
        return -1;
    }
}

/******************************************************************************************************************//**
 * Shutdown the LED setting
 * Freeze the dynamic memory which was already allocated before.
 *********************************************************************************************************************/
void led_shutdown()
{
    /* Release memory allocated for LED setting */
    free(gp_led_strip);

    /* Check that whether memory is allocate success or not */
    if(NULL == gp_led_strip)
    {
        printf("LED shutdown success /n");
    }
    else
    {
        printf("LED shutdown failure /n");
    }
}

/******************************************************************************************************************//**
 * Sets the color of a specific pixel at the given 'index'.
 * Uses 3 separate 8-bit values for Red, Green, and Blue.
 * Green (23-16) | Red (15 -8) | Blue
 *********************************************************************************************************************/
void led_set_pixel_color(size_t index, uint8_t r, uint8_t g, uint8_t b)
{
    /* Set the color of a specific pixel */
    gp_led_strip[index] = ((g << 16) | (r << 8) | b) & LED_MASK_BIT;
}

/******************************************************************************************************************//**
 * Fills the entire strip with a single color.
 * Green (23-16) | Red (15 -8) | Blue
 *********************************************************************************************************************/
void led_fill(uint8_t r, uint8_t g, uint8_t b)
{
    /* Fill the color setting */
    uint32_t led_fill = ((g << 16) | (r << 8) | b) & LED_MASK_BIT;

    /* Get size of led strip */
    size_t led_strip_size = sizeof(gp_led_strip)/sizeof(uint32_t);

    for (int i = 0; i < led_strip_size; i ++)
    {
        gp_led_strip[i] = led_fill;
    }
}

/******************************************************************************************************************//**
 * Set all led with color (0 ,0 ,0)
 * Green (23-16) | Red (15 -8) | Blue
 *********************************************************************************************************************/
void led_clear()
{
    /* Get size of led strip */
    size_t led_strip_size = sizeof(gp_led_strip)/sizeof(uint32_t);

    for (int i = 0; i < led_strip_size; i ++)
    {
        gp_led_strip[i] = 0;
    }
}

/******************************************************************************************************************//**
 * Gets a constant (read-only) pointer to the data buffer, ready to be "sent" out.
 *********************************************************************************************************************/
const uint32_t* led_get_buffer()
{

}

/******************************************************************************************************************//**
 * Gets the number of pixels on the LED strip.
 *********************************************************************************************************************/
size_t led_get_pixel_count()
{

}