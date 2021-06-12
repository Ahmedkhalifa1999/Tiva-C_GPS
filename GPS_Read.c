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
    float d;
	float lati;
	float longi;
    int i;
    for (i = 0; i < 5; i++){
        message[i] = ReadUART();
    }
    if(message[2] != 'G') goto read_again;
    if(message[3] != 'G') goto read_again;
    if(message[4] != 'A') goto read_again;
    for (i = 5; i < 44; i++) {
        message[i] = ReadUART();
    }
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
    
    d=100;
	
	for ( i = 0; i<10; i++)
	{
	lng2[i] = (longitude[i] -'0') ;

	if (i >= 3) {
	lng2[i] = (lng2[i]*100) / (60);
}
	longi += lng2[i] * d;
	d /= 10;
	}
	d = 10;
	for ( i = 0; i < 9; i++)
	{
		lat2[i] = (latitude[i] - '0');

		if (i >= 2) {
			lat2[i] = (lat2[i] * 100) / (60);
		}
		lati += lat2[i] * d;

		d /= 10;

	}

}

	int time_int[3] = {0,0,0};
	int n ;
	int k; 
	int v;
	for ( n = 0; n < 6; n++)
	{
		k = n / 2;
		v = 0;
		v = time_char[n] -'0' ;
			if (n % 2 == 0) {
				v *= 10;
			}
		time_int[k] += v;
	}



