#include "stdint.h"
#include "tm4c123gh6pm.h"

#define SYSCTL_RCGCGPIO_R (*((volatile unsigned long*)0x400FE108))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long*) 0x40025038))
#define GPIO_PORTF_DIR_R (*((volatile unsigned long*)0x40025400))
#define GPIO_PORTF_DEN_R (*((volatile unsigned long*)0x4002551C))

void LED_control(int distance){
	if (distance >=100){
		GPIO_PORTF_DATA_R |=0x02;
	}  
}
