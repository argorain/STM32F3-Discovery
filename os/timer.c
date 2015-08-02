#include <libopencm3/stm32/timer.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/f3/nvic.h>
#include <libopencmsis/core_cm3.h>

#include "timer.h"

void init_timer(void){
	//Enable TIMER6 clock
	rcc_periph_clock_enable(RCC_TIM3);

	//Setup TIMER6
	timer_reset(TIM3);
	timer_set_mode(TIM3, TIM_CR1_CKD_CK_INT_MUL_4, TIM_CR1_CMS_EDGE, TIM_CR1_DIR_UP); //div4, edge aligned, up count
	timer_set_period(TIM3, 18000); //T=1ms, counts = (fclk/div)*T = (72e6/4)*1e-3 = 18000
	timer_enable_irq(TIM3, TIM_DIER_UIE); //update interrupt enable

	nvic_enable_irq(NVIC_TIM3_IRQ);

	timer_enable_counter(TIM3);
}

extern void tim3_isr(void){
	timer_clear_flag(TIM3, TIM_SR_UIF);
	// TIM3->SR &= ~TIM_SR_UIF; // clear UIF flag
	//LED_BLUE_GPIO->ODR ^= (1 << LED_BLUE_PIN); // toggle LED state
	//while(1){
	gpio_toggle(GPIOE, GPIO15);
	//for (int i = 0; i < 2000000; i++) /* Wait a bit. */
	//		__asm__("nop");
	//}
}