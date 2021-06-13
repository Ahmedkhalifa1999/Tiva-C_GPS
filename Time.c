#include <stdio.h>

int time(int start[], int end[]) {
	int c[3];
	int i;
	for (i = 0; i < 3; i++) {
		c[i] = end[i] - start[i];
	}
	int x = c[0] * 3600 + c[1] * 60 + c[2];
	return x;
}
