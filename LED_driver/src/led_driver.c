/**********************************************************************************************************************
 * Includes
 *********************************************************************************************************************/
#include "./../include/led_driver.h"

/**********************************************************************************************************************
* Global variable
*********************************************************************************************************************/
uint32_t* gp_led_strip = NULL;

/**********************************************************************************************************************
* Function definition
*********************************************************************************************************************/

/******************************************************************************************************************//**
 * Initializes a buffer for the LED strip with the given number of pixels.
 * Returns 0 on success, -1 on failure
 *********************************************************************************************************************/
int led_init(size_t num_pixels)
{
    uint32_t total_size = num_pixels * LED_PIXEL_SIZE;
    gp_led_strip = (uint32_t*)malloc(total_size);

    /* Check that whether memory is allocate success or not */
    if(NULL != gp_led_strip)
    {
        printf("LED Initialize success \n");
        for (uint32_t i = 0; i < total_size; i++)
        {
            gp_led_strip[i] = 0;
        }
        return 0;
    }
    else
    {
        printf("LED Initialize failure \n");
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
    if (gp_led_strip != NULL)
    {
        printf("Freeing LED buffer...\n");
        free(gp_led_strip);
        gp_led_strip = NULL;
    }
    else
    {
        printf("LED buffer is already NULL, skip free.\n");
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
    gp_led_strip[index] = ((g << 16) | (r << 8) | b);
    if (0 != gp_led_strip[index])
        printf("Fill successful \n");
}

/******************************************************************************************************************//**
 * Fills the entire strip with a single color.
 * Green (23-16) | Red (15 -8) | Blue
 *********************************************************************************************************************/
void led_fill(uint8_t r, uint8_t g, uint8_t b)
{
    /* Fill the color setting */
    uint32_t led_fill = ((g << 16) | (r << 8) | b);

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
    return gp_led_strip;
}

/******************************************************************************************************************//**
 * Gets the number of pixels on the LED strip.
 *********************************************************************************************************************/
size_t led_get_pixel_count()
{
    size_t num_pixels = sizeof(gp_led_strip)/LED_PIXEL_SIZE;
    return num_pixels;
}