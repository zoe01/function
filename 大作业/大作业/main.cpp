#include<stdio.h>
#include <stdlib.h>
typedef struct points
{
	long x;
	long y;
}point;
extern int analyzeFunction(point *dot);
int main()
{
	point *dot;
	int size=analyzeFunction(dot);
	free;
	return 0;
}