// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Caminhada da Vergonha d...
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1860

#include <stdio.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

int px[50050], py[50050], N, X, i;

double max(double a, double b){
	if(a>b) return a;
	else return b;
}

double dst(double x, int j){
	double ax=px[j]-x, ay=py[j];
	return sqrt(ax*ax + ay*ay);
}

double func(double x){
	
	double ret=0.0; int j;
	for( j=0; j<N; j++ ){
		ret=max(ret, dst(x, j));
	}
	
	return ret;
}


int main()
{
	
	scanf("%d %d", &N, &X);
	
	for( i=0; i<N; i++ ) scanf("%d %d", &px[i], &py[i]);
	
	double x;
	
	double l=0.0, r=X;
	for( i=0; i<250; i++ ){
		
		double m1=(l*2.0+r)/3.0,
			   m2=(l+r*2.0)/3.0;
			
		
		if( func(m1) < func(m2) ) r=m2, x=m1;
		else l=m1, x=m2;
		
	}
	
	printf("%.2lf %.2lf\n", x, func(x));
	
	return 0;
	
}
