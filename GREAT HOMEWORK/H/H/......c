#include<stdio.h>
#include<math.h>
#define M 2
double shu(double a[M],double t) 
    int i=0,j=
	for(i=0;1<=20;i++)
	   t=a[i];
	   for(j=i+1;j<21;j++)
	      if(fabs(t)>=fabs(a[j]))
	         t=t;
	      else
	         t=a[j];
	   return fabs(t);      
}
