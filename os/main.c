#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencmsis/core_cm3.h>

#include "system.h"


#include "gpio.h"


int main(void){
	init_mcu();

	while (1) {
#ifndef DEBUG
		__WFI();
#else
		__asm__("nop");
#endif
	}

	return 0;
}