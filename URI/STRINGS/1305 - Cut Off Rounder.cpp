// Author: Gustavo Policarpo
// Name: Cut Off Rounder
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1305

#include <bits/stdc++.h>
using namespace std;

#define error 1e-10

int main()
{
	double num, cut;
	while(scanf("%lf %lf", &num, &cut) !=EOF){
		int aux=num;
		num-=aux;
		if(num-cut>error) aux++;
		printf("%d\n", aux);	
	}
return 0;
}
