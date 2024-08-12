/*
 * led.c
 *
 *  Created on: Jul 31, 2024
 *      Author: sauli
 */

#include <stdint.h>
#include "led.h"


void init_leds(void){
	RCC_AHB1ENR_t* pAHB1ENR = (RCC_AHB1ENR_t*)(0x40023800 + 0x30);

	pAHB1ENR->gpioc_en = 1;

	GPIOx_MODER_t* pGPIOc_MODER = (GPIOx_MODER_t*)0x40020800;

	pGPIOc_MODER->moder0 = 1;
	pGPIOc_MODER->moder1 = 1;
	pGPIOc_MODER->moder2 = 1;
	pGPIOc_MODER->moder3 = 1;

	led_on(RED_LED);
	led_on(GREEN_LED);
	led_on(YELLOW_LED);
	led_on(BLUE_LED);

	delay(DELAY_500_MS);

	led_off(RED_LED);
	led_off(GREEN_LED);
	led_off(YELLOW_LED);
	led_off(BLUE_LED);

	delay(DELAY_500_MS);

	led_on(RED_LED);
	led_on(GREEN_LED);
	led_on(YELLOW_LED);
	led_on(BLUE_LED);
}


void led_on(uint8_t led_pin){
	uint32_t* GPIOc_ODR = (uint32_t*)(0x40020800 + 0x14);
	*GPIOc_ODR |= (1 << led_pin);
}


void led_off(uint8_t led_pin){
	uint32_t* GPIOc_ODR = (uint32_t*)(0x40020800 + 0x14);
	*GPIOc_ODR &= ~(1 << led_pin);
}


void delay(uint32_t MS){
	uint32_t cycles_per_ms = 1600;
	uint32_t total_cycles = cycles_per_ms * MS;
	for(int i = 0; i < total_cycles; i++){
		continue;
	}
}
