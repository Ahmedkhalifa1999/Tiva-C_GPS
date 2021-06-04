#include "stdint.h"
#include "C:/Keil/TExaSware/tm4c123gh6pm.h"
void SystemInit() {}
void led_on (int a);

#define SYSCTL_RCGCGPIO_R (*((volatile unsigned long*)0x400FE108))
		#define GPIO_PORTF_DATA_R (*((volatile unsigned long*) 0x40025038))
			#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))
				#define GPIO_PORTF_DEN_R (*((volatile unsigned long* )0x4002551C))
void led_on(int a);	
int main ()
				{
					SYSCTL_RCGCGPIO_R |=0x20;
					GPIO_PORTF_DEN_R = 0x0E;
					GPIO_PORTF_DIR_R = 0x0E;
				}
					
	void led_on(int a){
	if (a>=100){
		GPIO_PORTF_DATA_R |=0x02;
	}  
	}
