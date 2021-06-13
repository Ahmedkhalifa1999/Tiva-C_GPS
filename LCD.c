#define F_CPU 16000000UL

#include "stdint.h"
#include "tm4c123gh6pm.h"
#include "Delay.h"



void init_LCD();
void LCD_command (unsigned char command);
void LCD_write (unsigned char data);



/*int main()
{ 
	init_LCD();
	delay_milli(100);
	while(1)
	{
	
	LCD_command (0x0C);//Display on , currsor off
	LCD_command (0x01);		//clear display screen
	LCD_command (0x80); // go to most left posision on 1st line	
	delay_milli (500);
	
	
	
		//writing
		
		for (uint8_t i=0; i<5; i++)
		{
			// char test [a,b,c] ;
		LCD_write( /test/ );
		delay_milli(100);
		}
		LCD_command (0xC0);  //move cursor to next line start
		delay_milli(100);
		LCD_command (0x0C);  //display on, cursor off
		delay_milli(100);
		for (uint8_t i=0; i<5; i++)
		{
			// char test [a,b,c] ;
		LCD_write( /test/ );
		delay_milli(100);
		}
	}
		
	}
  //writing_end
 */
void init_LCD(void)
{
	LCD_command (0x38); //Send 8-bit data
	delay_milli(1);
	LCD_command (0x06); //increment cursor
	delay_milli(1);
	LCD_command (0x0F); //Display on
	delay_milli(1);
	LCD_command (0x01);		//clear display screen
	delay_milli(1);
	
}


//send command on LCD 
void LCD_command(unsigned char command)
{
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
	
if(command <4) delay_milli(2); else delay_micro(37); } void LCD_Data(unsigned char data) { GPIO_PORTB_DATA_R |=0x04; //RS=1, E=0,RW=0

	
GPIO_PORTA_DATA_R &=  ~0xC0;	
GPIO_PORTA_DATA_R |=(data<<0);  
GPIO_PORTD_DATA_R &=  ~0xC0;	
GPIO_PORTD_DATA_R |=(data<<2);       
GPIO_PORTE_DATA_R &=  ~0x03;	
GPIO_PORTE_DATA_R |=(data>>2);       
GPIO_PORTF_DATA_R &=  ~0x0C;	
GPIO_PORTF_DATA_R |=(data<<2);

GPIO_PORTD_DATA_R |=0x04;
GPIO_PORTB_DATA_R &= ~0x0C; //RS(B2) =0, RW(B3)=0
GPIO_PORTD_DATA_R &= ~0x04; //E =0
delay_micro(0);
 
}

