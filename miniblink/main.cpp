#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

extern "C" {
	#include "gpio.h"
}

int main(void){
	int i;

	gpio_setup();

	/* Blink the LED (PC8) on the board. */
	while (1) {
		/* Using API function gpio_toggle(): */
		gpio_toggle(GPIOE, GPIO12);	/* LED on/off */
		for (i = 0; i < 2000000; i++) /* Wait a bit. */
			__asm__("nop");

	}

	return 0;
}