/*
 * main.h
 *
 *  Created on: Feb 6, 2024
 *      Author: sauli
 */

#ifndef MAIN_H_
#define MAIN_H_


typedef struct{
	uint32_t gpioa_en : 1;
	uint32_t gpiob_en : 1;
	uint32_t gpioc_en : 1;
	uint32_t gpiod_en : 1;
	uint32_t gpioe_en : 1;
	uint32_t reserved1 : 2;
	uint32_t gpioh_en : 1;
	uint32_t reserved2 : 4;
	uint32_t crc_en : 1;
	uint32_t reserved3 : 8;
	uint32_t dma1_en : 1;
	uint32_t dma2_en : 1;
	uint32_t reserved4: 9;
}RCC_AHB1ENR_t;


typedef struct{
	uint32_t MODER0 : 2;
	uint32_t MODER1 : 2;
	uint32_t MODER2 : 2;
	uint32_t MODER3 : 2;
	uint32_t MODER4 : 2;
	uint32_t MODER5 : 2;
	uint32_t MODER6 : 2;
	uint32_t MODER7 : 2;
	uint32_t MODER8 : 2;
	uint32_t MODER9 : 2;
	uint32_t MODER10 : 2;
	uint32_t MODER11 : 2;
	uint32_t MODER12 : 2;
	uint32_t MODER13 : 2;
	uint32_t MODER14 : 2;
	uint32_t MODER15 : 2;
}GPIOx_MODER_t;


typedef struct{
	uint32_t P0 : 1;
	uint32_t P1 : 1;
	uint32_t P2 : 1;
	uint32_t P3 : 1;
	uint32_t P4 : 1;
	uint32_t P5 : 1;
	uint32_t P6 : 1;
	uint32_t P7 : 1;
	uint32_t P8 : 1;
	uint32_t P9 : 1;
	uint32_t P10 : 1;
	uint32_t P11 : 1;
	uint32_t P12 : 1;
	uint32_t P13 : 1;
	uint32_t P14 : 1;
	uint32_t P15 : 1;
	uint32_t reserved : 16;
}GPIOx_IDR_t;


typedef struct{
	uint32_t MODER0 : 2;
	uint32_t MODER1 : 2;
	uint32_t MODER2 : 2;
	uint32_t MODER3 : 2;
	uint32_t MODER4 : 2;
	uint32_t MODER5 : 2;
	uint32_t MODER6 : 2;
	uint32_t MODER7 : 2;
	uint32_t MODER8 : 2;
	uint32_t MODER9 : 2;
	uint32_t MODER10 : 2;
	uint32_t MODER11 : 2;
	uint32_t MODER12 : 2;
	uint32_t MODER13 : 2;
	uint32_t MODER14 : 2;
	uint32_t MODER15 : 2;
}GPIOx_PUPDR_t;


typedef struct{
	uint32_t P0 : 1;
	uint32_t P1 : 1;
	uint32_t P2 : 1;
	uint32_t P3 : 1;
	uint32_t P4 : 1;
	uint32_t P5 : 1;
	uint32_t P6 : 1;
	uint32_t P7 : 1;
	uint32_t P8 : 1;
	uint32_t P9 : 1;
	uint32_t P10 : 1;
	uint32_t P11 : 1;
	uint32_t P12 : 1;
	uint32_t P13 : 1;
	uint32_t P14 : 1;
	uint32_t P15 : 1;
	uint32_t reserved : 16;
}GPIOx_ODR_t;


#endif /* MAIN_H_ */
