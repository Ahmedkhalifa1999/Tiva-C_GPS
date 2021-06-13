#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "Delay.h"


void LCD_command(int command) {
    GPIO_PORTB_DATA_R &= ~0x0C; //RS(B2) =0, RW(B3)=0
    GPIO_PORTD_DATA_R &= ~0x04; //E =0 (D2)
    GPIO_PORTA_DATA_R &=  ~0xC0;
    GPIO_PORTA_DATA_R |=(command<<0);
    GPIO_PORTD_DATA_R &=  ~0xC0;
    GPIO_PORTD_DATA_R |=(command<<2);
    GPIO_PORTE_DATA_R &=  ~0x03;
    GPIO_PORTE_DATA_R |=(command>>2);
    GPIO_PORTF_DATA_R &=  ~0x0C;
    GPIO_PORTF_DATA_R |=(command<<2);



    GPIO_PORTD_DATA_R |=0x04; //E=1 to secure command
    delay_micro(0);
    GPIO_PORTB_DATA_R &= ~0x0C; //RS(B2) =0, RW(B3)=0
    GPIO_PORTD_DATA_R &= ~0x04; //E =0 (D2)

    if(command <4) delay_milli(2);
    else delay_micro(37);
}

void init_LCD() {
    LCD_command (0x38); //Send 8-bit data
    delay_milli(1);
    LCD_command (0x06); //increment cursor
    delay_milli(1);
    LCD_command (0x0F); //Display on
    delay_milli(1);
    LCD_command (0x01);     //clear display screen
    delay_milli(1);
}

void LCD_Data(char data) {
    GPIO_PORTB_DATA_R |=0x04; //RS=1, E=0,RW=0

    GPIO_PORTA_DATA_R = (GPIO_PORTA_DATA_R & 0xC0) | (0xC0&(data << 0));
    GPIO_PORTD_DATA_R = (GPIO_PORTA_DATA_R & 0xC0) | (0x30&(data << 2));
    GPIO_PORTE_DATA_R = (GPIO_PORTA_DATA_R & 0x03) | (0x0C&(data >> 2));
    GPIO_PORTF_DATA_R = (GPIO_PORTA_DATA_R & 0x0C) | (0x03&(data << 2));
   
    GPIO_PORTD_DATA_R |=0x04;
    GPIO_PORTB_DATA_R &= ~0x0C; //RS(B2) =0, RW(B3)=0
    GPIO_PORTD_DATA_R &= ~0x04; //E =0
 
}

void LCD_write(char data[], int size) {
	init_LCD();
	delay_milli(100);

	LCD_command (0x0C); //Display on , cursor off
	LCD_command (0x01);	//clear display screen
	LCD_command (0x80); //go to most left position on 1st line
	delay_milli (500);

	int i;
	for (i = 0; i < size; i++) {
	    LCD_Data(data[i]);
	    delay_milli(1);
	    LCD_command (0xC0);
	    LCD_command (0x0C);
	}
}
