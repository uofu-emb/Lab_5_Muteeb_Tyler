#include <stdio.h>
#include <pico/stdlib.h>
#include <pico/sync.h>

#define IN_PIN 27
#define OUT_PIN 14
#define LOOP 1
#define BUSY_LOOP

// measured delay 18 uS
int toggle = 1;
void irq_callback(uint gpio, uint32_t event_mask)
{
    int j = 0;
    int q = 0;
#ifdef BUSY_LOOP
    int i = 1024 * 1024;
    while (i)
        i--;
#endif
    if (gpio != IN_PIN)
        return;
    toggle = !toggle;

    if (event_mask & GPIO_IRQ_EDGE_RISE)
    {
        gpio_put(OUT_PIN, true);
    }
    else if (event_mask & GPIO_IRQ_EDGE_FALL)
    {
        gpio_put(OUT_PIN, false);
    }
}

int main(void)
{
    // inits everythin
    stdio_init_all();
    // sets up input pin for PWM
    // ask ashton here...
    gpio_init(IN_PIN);
    // seting GPIO to be input.
    gpio_set_dir(IN_PIN, GPIO_IN);

    gpio_init(OUT_PIN);
    gpio_set_dir(OUT_PIN, GPIO_OUT);
    gpio_put(OUT_PIN, toggle);
    // set the  intrput here
    gpio_set_irq_enabled_with_callback(IN_PIN, GPIO_IRQ_EDGE_RISE | GPIO_IRQ_EDGE_FALL, true, irq_callback);
    // what= doe  wfi do
    while (1)
        __wfi();
    return 0;
}
