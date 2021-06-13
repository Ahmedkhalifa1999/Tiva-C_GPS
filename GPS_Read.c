#include "tm4c123gh6pm.h"


char ReadUART() {
    while(!(UART1_FR_R && 0x010)) {
        return (UART1_DR_R & 0x00FF);
    }
    return 0;
}

int ReadGPS(float pos[], int time[]) {
    char messageType[5];
    char time_char[9];
    char latitude[6];
    char longitude[10];
    char Read;
    int i;
    read_again:
    while (ReadUART() != 36);
    for (i = 0; i < 5; i++){
        messageType[i] = ReadUART();
    }
    if(messageType[2] != 'G') goto read_again;
    if(messageType[3] != 'G') goto read_again;
    if(messageType[4] != 'A') goto read_again;
    ReadUART();
    Read = ReadUART();
    i = 0;
    while (Read != ',') {
        time_char[i] = Read;
        i++;
        Read = ReadUART();
        if (Read == '.') {
            ReadUART();
            ReadUART();
            break;
        }
    }
    ReadUART();
    Read = ReadUART();
    i = 0;
    while (Read != ',') {
        if (Read != '.') {
            latitude[i] = Read;
            i++;
        }
        Read = ReadUART();
    }
    while(ReadUART() != ',');
    Read = ReadUART();
    i = 0;
    while (Read != ',') {
        if (Read != '.') {
            longitude[i] = Read;
            i++;
        }
        Read = ReadUART();
    }
    while(ReadUART() != ',');

    if (ReadUART() == '0') return 0;
    

    int d;
    int lng2[10];
    int lat2[9];


    d=100;
	for (i = 0; i < 10; i++){
	    lng2[i] = (longitude[i] -'0');

	    if (i >= 3) {
	        lng2[i] = (lng2[i]*100) / (60);
	    }
	    pos[0] += lng2[i] * d;
	    d /= 10;
	}

	d = 10;
	for (i = 0; i < 9; i++){
		lat2[i] = (latitude[i] - '0');
		if (i >= 2) {
			lat2[i] = (lat2[i] * 100) / (60);
		}
		pos[1] += lat2[i] * d;
		d /= 10;
	}

	int k; 
	int v;
	for (i = 0; i < 6; i++){
		k = i / 2;
		v = 0;
		v = time_char[i] -'0' ;
		if (i % 2 == 0) {
			v *= 10;
		}
		time[k] += v;
	}
	return 1;
}


