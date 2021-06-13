#include "stdint.h"
#include "tm4c123gh6pm.h"

void sevseg(int a) {
	int digits[3];
	digits[2]= a / 100;
	digits[1] = (a - digits[2]*100) / 10;
	digits[0] = (a - digits[2]*100 - digits[1]*10);
	
	GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & 0xC3) | (0x3C&(digits[0] << 2));
	GPIO_PORTB_DATA_R = (GPIO_PORTB_DATA_R & 0x0F) | (0xF0&(digits[1] << 4));
	GPIO_PORTE_DATA_R = (GPIO_PORTE_DATA_R & 0xC3) | (0x3C&(digits[2] << 2));
}
