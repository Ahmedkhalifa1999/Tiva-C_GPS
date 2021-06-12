#include "C:/Keil/ARM/BIN/tm4c123gh6pm.h"
#include "stdint.h"

void SystemInit(){}

#define INT_GPIOA        // GPIO Port A
#define INT_GPIOB        // GPIO Port B
#define INT_GPIOE        // GPIO Port E
#define INT_GPIOF        // GPIO Port F
	
#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define SYSCTL_PRGPIO_R         (*((volatile unsigned long *)0x400FEA08))
	
#define GPIO_PORTA_DIR_R        (*((volatile unsigned long *)0x40004400))
#define GPIO_PORTA_DEN_R        (*((volatile unsigned long *)0x4000451C))
#define GPIO_PORTA_AMSEL_R      (*((volatile unsigned long *)0x40004528))
#define GPIO_PORTA_AFSEL_R      (*((volatile unsigned long *)0x40004420))
#define GPIO_PORTA_PCTL_R       (*((volatile unsigned long *)0x4000452C))
#define GPIO_PORTA_DATA_R       (*((volatile unsigned long *)0x400043FC))
#define GPIO_PORTA_PUR_R        (*((volatile unsigned long *)0x40004510))
	
#define GPIO_PORTB_DIR_R        (*((volatile unsigned long *)0x40005400))
#define GPIO_PORTB_DEN_R        (*((volatile unsigned long *)0x4000551C))
#define GPIO_PORTB_AMSEL_R      (*((volatile unsigned long *)0x40005528))
#define GPIO_PORTB_AFSEL_R      (*((volatile unsigned long *)0x40005420))
#define GPIO_PORTB_PCTL_R       (*((volatile unsigned long *)0x4000552C))
#define GPIO_PORTB_DATA_R       (*((volatile unsigned long *)0x400053FC))
#define GPIO_PORTB_PUR_R        (*((volatile unsigned long *)0x40005510))

#define GPIO_PORTE_DIR_R        (*((volatile unsigned long *)0x40024400))
#define GPIO_PORTE_DEN_R        (*((volatile unsigned long *)0x4002451C))
#define GPIO_PORTE_AMSEL_R      (*((volatile unsigned long *)0x40024528))
#define GPIO_PORTE_AFSEL_R      (*((volatile unsigned long *)0x40024420))
#define GPIO_PORTE_PCTL_R       (*((volatile unsigned long *)0x4002452C))
#define GPIO_PORTE_PUR_R        (*((volatile unsigned long *)0x40024510))

#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_AMSEL_R      (*((volatile unsigned long *)0x40025528))	
#define GPIO_PORTF_AFSEL_R      (*((volatile unsigned long *)0x40025420))
#define GPIO_PORTF_PCTL_R       (*((volatile unsigned long *)0x4002552C))
#define GPIO_PORTF_PUR_R        (*((volatile unsigned long *)0x40025510))


int main(){
}

void init(void)

{
SYSCTL_RCGCGPIO_R|= 0x3F;
SYSCTL_RCGCUART_R|= 0x02;
	
while ((SYSCTL_PRGPIO_R&0x3F) == 0){};
	
GPIO_PORTA_DIR_R |= 0XFC;
GPIO_PORTA_DEN_R |= 0xFC;
GPIO_PORTA_AMSEL_R &= ~0xFC;
GPIO_PORTA_AFSEL_R &=~0xFC;
GPIO_PORTA_PCTL_R &= ~0xFFFFFF00;
GPIO_PORTA_DATA_R &= ~0xFC;
	
GPIO_PORTB_DIR_R |= 0XFC;
	
UART1_CTL_R &= ~0x00000001;
UART1_IBRD_R = 104;	
UART1_FBRD_R = 11;
UART1_LCRH_R = 0x00000070;
UART1_CTL_R |= 0x00000301;	

GPIO_PORTB_DEN_R |= 0xFF;
GPIO_PORTB_AMSEL_R &= ~0xFF;
	
GPIO_PORTB_AFSEL_R |= 0x03;
GPIO_PORTB_PCTL_R = (GPIO_PORTB_PCTL_R & 0xFFFFFF00)+ 0x00000011;
GPIO_PORTB_DATA_R &= ~0xFC;
	
GPIO_PORTD_DIR_R |= 0XCC;
GPIO_PORTD_DEN_R |= 0xCC;
GPIO_PORTD_AMSEL_R &= ~0xCC;
GPIO_PORTD_AFSEL_R &=~0xCC;
GPIO_PORTD_PCTL_R &= ~0xFF00FF00;
GPIO_PORTD_DATA_R &= ~0xCC;
		
GPIO_PORTE_DIR_R |= 0X3F;
GPIO_PORTE_DEN_R |= 0x3F;
GPIO_PORTE_AMSEL_R &= ~0x3F;
GPIO_PORTE_AFSEL_R &=~0x3F;
GPIO_PORTE_PCTL_R &= ~0x00FFFFFF;
GPIO_PORTE_DATA_R &= ~0x3F;
		
GPIO_PORTF_DIR_R |= 0X1E;
GPIO_PORTF_DEN_R |= 0x1E;
GPIO_PORTF_AMSEL_R &= ~0x1E;
GPIO_PORTF_AFSEL_R &=~0x1E;
GPIO_PORTF_PCTL_R &= ~0x0000FFFF0;
GPIO_PORTF_DATA_R &= ~0x1E;	
GPIO_PORTF_PUR_R |= 0x10;	

	
}
	

	