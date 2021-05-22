#include "stm32f4xx.h"                  // Device header

//nucleo board pushbutton PORTC - 13th pin PC13

int main(void)
{
	RCC->AHB1ENR |= 4;				//Enable port C
	RCC->AHB1ENR |= 1;				//Enable port A
	
	GPIOA->MODER |= 0x400;		//set as OUTPUT PA5, by default all pins are input
	GPIOC->MODER |= 0x00;			//not required default state as input
	
	while(1)
	{
		//default led will be off, while press the button led glows ON
		if(GPIOC->IDR & 0x2000)				//active HIGH, so if PC13 high default
		{
			GPIOA->ODR &= ~0x20;				// clearing a LED PA5 bit
			//GPIOA->BSRR = 0x002; 			//turn off LED PA5
		}
		else
		{
			  GPIOA->ODR |= 0x20; 				//setting a LED PA5 bit
				//GPIOA->BSRR = 0x20;				//turn on LED PA5
		}
	}
}
	