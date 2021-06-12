#include "tm4c123gh6pm.h"


char ReadUART() {
    while(!(UART1_FR_R && 0x010)) {
        return UART1_DR_R;
    }
    return 0;
}

int ReadGPS(double pos[], int time[]) {
    read_again:
    while (ReadUART() != '$');
    char message[44];
    char time_char[6];
    char latitude[9];
    char longitude[10];
    int i;
    for (i = 0; i < 5; i++){
        message[i] = ReadUART();
    }
    if(message[2] != 'G') goto read_again;
    if(message[3] != 'G') goto read_again;
    if(message[4] != 'A') goto read_again;
    for (i = 0; i < 6; i++) {
        time_char[i] = message[i+6];
    }
    for (i = 0; i < 4; i++) {
        latitude[i] = message[i+16];
    }
    for (i = 4; i < 9; i++) {
        latitude[i] = message[i+17];
    }
    for (i = 0; i < 5; i++) {
        longitude[i] = message[i+30];
    }
    for (i = 5; i < 10; i++) {
        longitude[i] = message[i+31];
    }
}




