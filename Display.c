
#include "stdint.h"
						//!!!!!!!!
#include "C:/Keil/TExaSware/tm4c123gh6pm.h"  //change file path!!!!
void SystemInit(){}
void numbreak(int c);
void disp();
void sevseg(int a[]); 

int main() {
	numbreak(123);

}
void numbreak(int c) {
	int  nu[3],n;
	nu[2]= c / 100;
	nu[1] = (c - nu[2]*100) / 10;
	nu[0] = (c - nu[2]*100 - nu[1]*10);

	 
	sevseg(nu);
	
}
void sevseg(int a[]) {

	//int o1 = ;//the first pin you start from in the port (offset1) least signficant digit
	//int o2= ; //offset 2
	//int o3= ;  //offset 3
	
	/*
	int pins =0;
	int n = 0; 
	for (n = 0; n < 3; n++) {               
		
		a[n] <<= 4*n;
		pins |= a[n];			
		
	}
	deleted*/
	
//un comment the following 2 lines after edting 
	//portL-digwrite &= ~(0xfff << o1);//(1111 1111 1111)base2 //reset all port-pins to zero, O is the starting pin in the port (offset)
	//portL-digwrite &= ~(0xfff << o2);
	//portL-digwrite &= ~(0xfff << o3);
	// portL-digwrite  |= (a[0]<<o1);  // least signficant digit
	// portL-digwrite  |= (a[1]<<o2);
	// portL-digwrite  |= (a[2]<<o3);
	
	}
