#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/timer.h>
#include <libopencm3/cm3/nvic.h>
#include <libopencm3/stm32/f3/nvic.h>

#include "timer.h"

void init_timer(void){
	//Enable TIMER6 clock
	rcc_periph_clock_enable(RCC_TIM3);

	//Setup TIMER6
	timer_reset(TIM3);
	timer_set_mode(TIM3, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP); //div4, edge aligned, up count
	timer_set_period(TIM3, 16000); //T=1ms, counts = (fclk/div)*T = (64e6/4)*1e-3 = 18000
	timer_enable_irq(TIM3, TIM_DIER_UIE); //update interrupt enable
	timer_enable_counter(TIM3);

	nvic_enable_irq(NVIC_TIM3_IRQ);
}

static int counter=0;
#define BASE 500

void tim3_isr(void){
	timer_clear_flag(TIM3, TIM_SR_UIF);
	// TIM3->SR &= ~TIM_SR_UIF; // clear UIF flag
	//LED_BLUE_GPIO->ODR ^= (1 << LED_BLUE_PIN); // toggle LED state
	//while(1){
	if(counter>BASE){
		gpio_toggle(GPIOE, GPIO15);
	}
	if(counter>BASE*2){
		gpio_toggle(GPIOE, GPIO14);
	}
	if(counter>BASE*3){
		gpio_toggle(GPIOE, GPIO13);
	}
	if(counter>BASE*4){
		gpio_toggle(GPIOE, GPIO12);
	}
	if(counter>BASE*5){
		gpio_toggle(GPIOE, GPIO11);
	}
	if(counter>BASE*6){
		gpio_toggle(GPIOE, GPIO10);
	}
	if(counter>BASE*7){
		gpio_toggle(GPIOE, GPIO9);
	}
	if(counter>BASE*7){
		gpio_toggle(GPIOE, GPIO8);
		counter=0;
	}
	if(counter>BASE*8){
		counter=0;
	}
	counter++;
	//for (int i = 0; i < 2000000; i++) /* Wait a bit. */
	//		__asm__("nop");
	//}
}