#include "stdio.h"
#include "math.h"
#define R 6371
#define PI 3.14

double distance(double lon1, double lon2, double lat1, double lat2)
{
	double distance;
	double a = sin((lat2 - lat1) * PI / 360) * sin((lat2 - lat1) * PI / 360);
	double b = sin((lon2 - lon1) * PI / 360) * sin((lon2 - lon1) * PI / 360);
	distance = abs(2000 * R * asin(sqrt(a + cos(lat2 * PI / 180) * cos(lat1 * PI / 180) * b)));
	if (distance < 0.6) return distance;
	else return 0.6;
}


