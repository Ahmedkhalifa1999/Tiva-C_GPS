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
	int totalDistance = 0;
	int i;
	//double previousLat, previousLon, currentLat, currentLon;
	init();
	while(1) {
	    LED_control(totalDistance);
	    sevseg(totalDistance);
	    totalDistance++;
	    i = 0;
	    while (i < 250000) i++;
	}
}
