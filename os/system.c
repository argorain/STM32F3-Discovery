
#include <libopencm3/stm32/rcc.h>
#include <libopencmsis/core_cm3.h>
//#include <libopencm3/stm32/cortex.h>


#include "gpio.h"

#include "timer.h"
#include "system.h"



void init(void){
	__disable_irq();

	rcc_clock_setup_hsi(&hsi_8mhz[CLOCK_64MHZ]);

	gpio_setup();

	init_timer();

	__enable_irq();
}