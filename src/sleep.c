#include <stdio.h>
#include <pico/stdlib.h>

#define OUT_PIN 14
#define DELAY_MS 100

#define BUSY_LOOP 

int pico_led_init(void)
{
#if defined(PICO_DEFAULT_LED_PIN)
    // A device like Pico that uses a GPIO for the LED will define PICO_DEFAULT_LED_PIN
    // so we can use normal GPIO functionality to turn the led on and off
    gpio_init(PICO_DEFAULT_LED_PIN);
    gpio_set_dir(PICO_DEFAULT_LED_PIN, GPIO_OUT);
    return PICO_OK;
#elif defined(CYW43_WL_GPIO_LED_PIN)
    // For Pico W devices we need to initialise the driver etc
    return cyw43_arch_init();
#endif
}

// Turn the led on or off
void pico_set_led(bool led_on)
{
#if defined(PICO_DEFAULT_LED_PIN)
    // Just set the GPIO on or off
    gpio_put(PICO_DEFAULT_LED_PIN, led_on);
#elif defined(CYW43_WL_GPIO_LED_PIN)
    // Ask the wifi "driver" to set the GPIO on or off
    cyw43_arch_gpio_put(CYW43_WL_GPIO_LED_PIN, led_on);
#endif
}

int main(void)
{
    int toggle = 0;
    stdio_init_all();

    // Create new GPIO variable called OUT_PIN.
    gpio_init(OUT_PIN);
    pico_led_init();

    // Set the OUT_PIN as Output pin.
    gpio_set_dir(OUT_PIN, GPIO_OUT);

    // Toggle our output OUT_PIN to 0
    gpio_put(OUT_PIN, toggle);
    pico_set_led(toggle);

    while (true)
    {
        toggle = !toggle;
        gpio_put(OUT_PIN, toggle);
        pico_set_led(toggle);
        sleep_ms(DELAY_MS);
#ifdef BUSY_LOOP
        int i = 1024 * 1024;
        while (i)
            i--;
#endif
    }
}
