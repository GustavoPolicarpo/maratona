// Author: Gustavo Policarpo
// Name: PoGro Challenge
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2517

#include <stdio.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

int A, B, C, xc, yc, xf, i;

double dst(double x, double y){
	return sqrt( (x-xc)*(x-xc) + (y-yc)*(y-yc) );
}
double func(double x){
	double y=-x*x/A-x/B+C;
	return dst(x, y);
}

int main()
{
	
	//-x²/10 - x/2 + 5
	
	while(scanf("%d %d %d", &A, &B, &C) !=EOF){
		scanf("%d %d %d", &xc, &yc, &xf);
		
		double ans=123456789, l=0.0, r=xf, x;
		
		for( i=0; i<105; i++ ){
			
			double m1=(l*2.0+r)/3.0,
			   	   m2=(l+r*2.0)/3.0;
			   	   
			if( func(m1) < func(m2) ) r=m2, x=m1;
			else l=m1, x=m2;
			
		}
		
		printf("%.2lf\n", func(x));
		
	}
	
	return 0;
	
}
