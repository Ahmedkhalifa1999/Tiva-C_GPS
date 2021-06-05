#include "tm4c123gh6pm.h"
#include "stdint.h"

//#define INT_GPIOA        // GPIO Port A
//#define INT_GPIOB        // GPIO Port B
//#define INT_GPIOE        // GPIO Port E
//#define INT_GPIOF        // GPIO Port F
//	
//#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
//#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))
//	
//#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
//#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
//#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
//#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
//#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
//#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
//#define GPIO_PORTA_PUR_R        (*((volatile unsigned long *)0x40004510))
//	
//#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
//#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
//#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
//#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
//#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))
//#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
//#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))

//#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
//#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
//#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
//#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
//#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))
//#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))
//	
//#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
//#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
//#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
//#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
//#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))	
//#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
//#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
//#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))


void init(void)

{
SYSCTL_RCGCGPIO_R|= 0x33;
while ((SYSCTL_PRGPIO_R&0x33) == 0){};
	
GPIO_PORTA_DIR_R |= 0X3C;
GPIO_PORTA_DEN_R |= 0x3C;
GPIO_PORTA_AMSEL_R &= ~0x3C;
GPIO_PORTA_AFSEL_R &=~0x3C;
GPIO_PORTA_PCTL_R &= ~0x00FFFF00;
GPIO_PORTA_DATA_R &= ~0x3C;
	
GPIO_PORTB_DIR_R |= 0XF0;
GPIO_PORTB_DEN_R |= 0xF0;
GPIO_PORTB_AMSEL_R &= ~0xF0;
GPIO_PORTB_AFSEL_R &=~0xF0;
GPIO_PORTB_PCTL_R &= ~0x0000FFFF;
GPIO_PORTB_DATA_R &= ~0xF0;
		
GPIO_PORTE_DIR_R |= 0X3C;
GPIO_PORTE_DEN_R |= 0x3C;
GPIO_PORTE_AMSEL_R &= ~0x3C;
GPIO_PORTE_AFSEL_R &=~0x3C;
GPIO_PORTE_PCTL_R &= ~0x00FFFF00;
GPIO_PORTE_DATA_R &= ~0x3C;
		
GPIO_PORTF_DIR_R |= 0X02;
GPIO_PORTF_DEN_R |= 0x02;
GPIO_PORTF_AMSEL_R &= ~0x02;
GPIO_PORTF_AFSEL_R &=~0x02;
GPIO_PORTF_PCTL_R &= ~0x000000F0;
GPIO_PORTF_DATA_R &= ~0x02;		
	
}
	

	
