// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Flores Coloridas
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1219

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

void areapp(double a, double b, double c)
{
	cout << fixed << setprecision(4)
	<< a-b << " "
	<< b-c << " "
	<< c << endl;
}

void areatt(double a, double b, double c)
{
	double p=(a+b+c)/2;
	
	double AT=sqrt(p*(p-a)*(p-b)*(p-c));
	double ACP=pow(AT/p,2)*(M_PI);
	double ACG=pow(((a*b*c)/(4*AT)),2)*(M_PI);
	
	areapp(ACG, AT, ACP);
	
	
}

int main()
{
	double A, B, C;
	while(cin >> A >> B >> C)
		areatt(A, B, C);
		

return 0;
}
