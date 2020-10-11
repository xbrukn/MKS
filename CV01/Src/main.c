/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include "stm32f0xx.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{

	RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
	GPIOA->MODER |= GPIO_MODER_MODER5_0;

	static const uint32_t pole[32] = {1,0,1,0,1,0,0,1,1,1,0,1,1,1,0,1,1,1,0,0,1,0,1,0,1,0,0,0,0,0,0,0}; //  data v poli

	while(1)
	{	


		// pro data v poli
		for(uint8_t i = 0; i < sizeof(pole); i++)
		{
			if(pole[i])
					{
						GPIOA->BSRR = (1<<5); // nastavit
					}
					else
					{
						GPIOA->BRR = (1<<5); // reset
					}
		 
			//GPIOA->ODR ^= (1<<5); // toggle - negování pinu

			for (volatile uint32_t j = 0; j < 100000; j++) // wait
					{

					}

		}
	}
}
