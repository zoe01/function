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
	point *dot = 0;
	int size=analyzeFunction(dot);
	int i;
	for (i = 0; i < size; i++){
		printf("%ld %ld", dot[i].x, dot[i].y);
	}
	free;
	return 0;
}