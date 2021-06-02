
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
	int pins =0;
	int n = 0; 
	//int o = ;//the first pin you start from in the port
	for (n = 0; n < 3; n++) {               
		
		a[n] <<= 4*n;
		pins |= a[n];			
		
	}
	
//un comment the following 2 lines
	//portL-digwrite &= ~(0xfff << O);--- //(1111 1111 1111) base2 //reset all port-pins to zero, O is the starting pin in the port (offset)
	//f  |= (pins<<O);
	
	}
