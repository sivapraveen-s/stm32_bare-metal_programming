//LED  - LD2 - D13 pin -  PA5 (STM32F446)
//AHB1 - PORTA clock bus
//RCC->AHB1ENR
//GPIOx_MODER
//GPIOx_ODR


/* STEPS to Configure GPIO
1. set the clock gatting to the respective
   RCC is a strucutre and AHB1EN is a member of the strucure
   RCC->AHB1ENR

2. set the pin as output-or-input
	i) Direction Register - set input or output
3. write or read the data of the pin
4. Each general-purpose I/O has 
   i) 4 32 bit configuration registers (GPIOx_MODER (set the mode I/O), GPIOx_OTYPER, GPIOx_OSPEEDR, GPIOx_PUPDR)
  ii) 2 32 bit data registers (GPIOx_IDR, GPIOx_ODR)
 iii) 1 32 bit set/reset register (GPIOx_BSRR)
  iv) 1 32 bit locking register (GPIOx_LCKR)
	 v) 2 32 bit alternate function selection register (GPIOx_AFRH, GPIOx_AFRL)
	 

Bit Set/reset Register (BSRR)
-Lower 16bits (half_word) turns on pin eg: 0x00000020 //turn on LED PA5 (15:0)
-upper 16bits turns off pin eg: 0x00200000 //turn off LED PA5 (31:16)
	 
	 
*/

#include "stm32f4xx.h"                  // Device header

void delayMs(int delay);					//prototype declaration

int main(void)
{
	RCC->AHB1ENR |= 1;											//setting enable clock for GPIOA
	//GPIOA->MODER = 0x400;										// 0100 0000 0000 - setting PA5 as Output, PORTA 5th pin as output
	//if we above statement, it will clear if any predefined changes done before, so need to set the bit without disturb the other bits in the same register
	GPIOA->MODER |= 0x400;

	while(1)
	{
			GPIOA->ODR |= 0x20;									//0b 0010 0000
		  delayMs(1000);		
		  GPIOA->ODR &= ~0x20;								// clearing a bit
		  delayMs(1000);
		
		/*
		another method
			GPIO->BSRR = 0x00000020;						// 0x20; set PA5 HIGH
			delayMs(100);
			GPIO->BSRR = 0x00200000;						// clear PA5 LOW
			delayMs(100);	
		*/
		
	}
	
}

void delayMs(int delay)
{
	int i;
	for(; delay > 0; delay --)
	{
			for(i = 0; i < 3195; i ++);
	}
}