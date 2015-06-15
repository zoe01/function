#include<stdio.h>
#include <stdlib.h>

typedef struct points
{
	double x;
	double y;
}point;
extern point* analyzeFunction();

int main()
{
	point *dot = 0;
	dot = analyzeFunction();
	int i;
	for (i = 1; i <= dot[0].x; i++){
		printf("%lf %lf\n", dot[i].x, dot[i].y);
	}
	free;
	return 0;
}