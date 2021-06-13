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
    float current_pos[2];
    float past_pos[2];
    int start_time[3];
    int end_time[3];
    int totalDistance = 0;
    init();
    sevseg(0);
    while(ReadGPS(past_pos, start_time) == 1);
    while(1) {
        ReadGPS(current_pos, end_time);
        totalDistance += distance(past_pos[0], current_pos[0], past_pos[1], current_pos[1]);
        sevseg(totalDistance);
        past_pos[0] = current_pos[0];
        past_pos[1] = current_pos[1];
        LEDControl(totalDistance);
    }
    init();

}
