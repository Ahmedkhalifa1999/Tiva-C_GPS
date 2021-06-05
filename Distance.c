#include "stdio.h"
#include "math.h"
#define R 6371
#define PI 3.14

double distance(double lat1, double lat2, double lon1, double lon2)
{
	double distance;
	double a = sin((lat2 - lat1) * PI / 360) * sin((lat2 - lat1) * PI / 360);
	double b = sin((lon2 - lon1) * PI / 360) * sin((lon2 - lon1) * PI / 360);
	distance = 2000 * R * asin(sqrt(a + cos(lat2 * PI / 180) * cos(lat1 * PI / 180) * b));
	return distance;
}
//int main() 
//{
//	double lat1 = 29.99862;
//	double lat2 = 29.99755;
//	double lon1 = 31.17397;
//	double lon2 = 31.17319;
//	double x= distance( lat1, lat2,  lon1,  lon2);
//	printf("\n The distance covered is %lf meter\n\n" , x);
//	return 0;
//}


