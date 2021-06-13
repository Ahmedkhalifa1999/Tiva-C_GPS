#include "stdio.h"
#include "math.h"
#define R 6371
#define PI 3.14

float distance(float lon1, float lon2, float lat1, float lat2)
{
	float distance;
	float a = sin((lat2 - lat1) * PI / 360) * sin((lat2 - lat1) * PI / 360);
	float b = sin((lon2 - lon1) * PI / 360) * sin((lon2 - lon1) * PI / 360);
	distance = 2000 * R * asin(sqrt(a + cos(lat2 * PI / 180) * cos(lat1 * PI / 180) * b));
	return distance;
}


