#include "tm4c123gh6pm.h"
#include "stdint.h"

#define INT_GPIOA        // GPIO Port A
#define INT_GPIOD        // GPIO Port D
#define INT_GPIOF        // GPIO Port F
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))
#define GPIO_PORTA_AHB_DIR_R    (*((volatile unsigned long *)0x40058400))
#define GPIO_PORTA_AHB_DEN_R    (*((volatile unsigned long *)0x4005851C))
#define GPIO_PORTA_AHB_AMSEL_R  (*((volatile unsigned long *)0x40058528))
#define GPIO_PORTA_AHB_AFSEL_R  (*((volatile unsigned long *)0x40058420))
#define GPIO_PORTA_AHB_PCTL_R   (*((volatile unsigned long *)0x4005852C))
#define GPIO_PORTA_AHB_DATA_R   (*((volatile unsigned long *)0x400583FC))
#define GPIO_PORTA_AHB_PUR_R    (*((volatile unsigned long *)0x40058510))
#define GPIO_PORTD_LOCK_R       (*((volatile unsigned long *)0x40007520))
#define GPIO_PORTD_CR_R         (*((volatile unsigned long *)0x40007524))
#define GPIO_PORTD_DIR_R        (*((volatile unsigned long *)0x40007400))
#define GPIO_PORTD_DEN_R        (*((volatile unsigned long *)0x4000751C))
#define GPIO_PORTD_AMSEL_R      (*((volatile unsigned long *)0x40007528))
#define GPIO_PORTD_AFSEL_R      (*((volatile unsigned long *)0x40007420))
#define GPIO_PORTD_PCTL_R       (*((volatile unsigned long *)0x4000752C))
#define GPIO_PORTD_DATA_R       (*((volatile unsigned long *)0x400073FC))
#define GPIO_PORTD_PUR_R        (*((volatile unsigned long *)0x40007510))
#define GPIO_PORTF_LOCK_R       (*((volatile unsigned long *)0x40025520))
#define GPIO_PORTF_CR_R         (*((volatile unsigned long *)0x40025524))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))	
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))

void init(void)
{
SYSCTL_RCGCGPIO_R|= 0x29;
while ((SYSCTL_PRGPIO_R&0x29) == 0){};
	
GPIO_PORTA_DIR_R |= 0X3C;
GPIO_PORTA_DEN_R |= 0x3C;
GPIO_PORTA_AMSEL_R &= ~0x3C;
GPIO_PORTA_AFSEL_R &=~0x3C;
GPIO_PORTA_PCTL_R &= ~0x00FFFF00;
GPIO_PORTA_DATA_R &= ~0x3C;
		
GPIO_PORTD_LOCK_R = 0x4C4F434B;
GPIO_PORTD_CR_R |= 0x0F;
GPIO_PORTD_DIR_R |= 0X0F;
GPIO_PORTD_DEN_R |= 0x0F;
GPIO_PORTD_AMSEL_R &= ~0x0F;
GPIO_PORTD_AFSEL_R &=~0x0F;
GPIO_PORTD_PCTL_R &= ~0x0000FFFF;
GPIO_PORTD_DATA_R &= ~0x0F;
		
GPIO_PORTF_LOCK_R = 0x4C4F434B;
GPIO_PORTF_CR_R |= 0x0F;
GPIO_PORTF_DIR_R |= 0X0F;
GPIO_PORTF_DEN_R |= 0x0F;
GPIO_PORTF_AMSEL_R &= ~0x0F;
GPIO_PORTF_AFSEL_R &=~0x0F;
GPIO_PORTF_PCTL_R &= ~0x0000FFFF;
GPIO_PORTF_DATA_R &= ~0x0F;		
	
}
	
	
	
