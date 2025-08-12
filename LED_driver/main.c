/***********************************************************************************************************************
 * Includes
 **********************************************************************************************************************/
#include "led_driver.h"

/**********************************************************************************************************************
* Functions
*********************************************************************************************************************/
int main ()
{
    /* Initialize a LED strip with 10 pixels */
    size_t num_pixel = 10;
    const uint32_t* pbuf;
    led_init(num_pixel);

    /* Check if initialization buffer is '0' */
    pbuf = led_get_buffer();
    uint32_t total_size = num_pixel*LED_PIXEL_SIZE;
    for (uint32_t i = 0; i < total_size; i++)
    {
        if(0 != pbuf[i])
            printf("Initialize buffer should be '0', please check at byte: %u \n", i);
    }

    /* Set Red(255, 0, 0) for first pixel (index 0) */
    printf("Fill RED for first pixed \n");
    led_set_pixel_color(0, 255, 0, 0);

    /* Set Blue(0, 0, 255) for 10th pixel (index 9) */
    printf("Fill Blue for 10th pixed \n");
    led_set_pixel_color(9, 0, 0, 255);

    /* Set White(255, 255, 255) for 5th pixel (index 4) */
    printf("Fill White for 5th pixed \n");
    led_set_pixel_color(4, 255, 255, 255);

    /* Point to address of LED strip */
    pbuf = led_get_buffer();
    printf("The color of LED[0] is: 0x%.8x\n", pbuf[0]);
    printf("The color of LED[9] is: 0x%.8x\n", pbuf[9]);
    printf("The color of LED[4] is: 0x%.8x\n", pbuf[4]);

    /* Fill all LED to green */
    printf("Fill all LED to green \n");
    led_fill(0,255,0);
    for (size_t i = 0; i < num_pixel; i++)
    {
    printf("The color of LED[%ld] is: 0x%.8x\n", i, pbuf[0]);
    }

    /* Shutdown led and release memory */
    led_shutdown();

    return 0;
}