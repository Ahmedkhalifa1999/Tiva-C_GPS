#include "stdint.h"
#include "tm4c123gh6pm.h"  
#include "InputOutput.h"
#include "Display.h" 
#include "Distance.h"
#include "LED.h"
#include "GPS_Read.h"
#include "LCD.h"
#include "Time.h"

void SystemInit() {}

int main() {
    //float postion[2]={10, 16};
    //float time[3]={1, 22, 33};
    //int ReadGPS(float pos[], int time[]);
   // int ReadGPS( , );

   // void LCD_write( "abc d 123" );
   init();
   init_LCD();
   LCD_write( "abc d 123", 9);
}
