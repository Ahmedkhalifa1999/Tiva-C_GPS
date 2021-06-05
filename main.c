#include "stdint.h"
#include "tm4c123gh6pm.h"  
#include "InputOutput.h"
#include "LED_On.h"
#include "Display.h" 
#include "Distance.h"

void SystemInit() {}

int main() {
	int totalDistance = 0;
	//double previousLat, previousLon, currentLat, currentLon;
	init();
	totalDistance = 150;
	LED_control(totalDistance);
	sevseg(123);
}
