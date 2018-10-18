// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pergunte à Geógrafa
// Nível: 5
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2521

#include <stdio.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

double GR(double u){
	return u*M_PI/180.0;
}

const double EPS = 1e-9;

int main()
{
	
	double r, a, b;
	while(scanf("%lf %lf %lf", &r, &a, &b) !=EOF){
		
		a=90-a;
		double z=-1*r*sin(GR(a))*cos(GR(b));
		double x=r*sin(GR(a))*sin(GR(b));
		double y=r*cos(GR(a));
		
		printf("%.2lf %.2lf %.2lf\n", x+EPS, y+EPS, z+EPS);
		
	}
	
	return 0;
	
}
