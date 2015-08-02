#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencmsis/core_cm3.h>

#include "system.h"


#include "gpio.h"


int main(void){
	int i;

	init();

	/* Blink the LED (PC8) on the board. */
	while (1) {
		/* Using API function gpio_toggle(): */
		gpio_toggle(GPIOE, GPIO8);	/* LED on/off */
		gpio_toggle(GPIOE, GPIO9);	/* LED on/off */
		gpio_toggle(GPIOE, GPIO10);	/* LED on/off */
		gpio_toggle(GPIOE, GPIO11);	/* LED on/off */
		gpio_toggle(GPIOE, GPIO12);	/* LED on/off */
		gpio_toggle(GPIOE, GPIO13);	/* LED on/off */
		gpio_toggle(GPIOE, GPIO14);	/* LED on/off */
		//gpio_toggle(GPIOE, GPIO15);	/* LED on/off */
		for (i = 0; i < 2000000; i++) /* Wait a bit. */
			__asm__("nop");

	}

	return 0;
}