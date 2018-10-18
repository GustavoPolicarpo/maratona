// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Volta
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1708

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define error 1e-4

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < char, int > ii;
typedef pair < double, int > iii;

int main()
{	
	double X, Y, x, y, aux;
	int out;
	scanf("%lf %lf", &X, &Y);
	x=1.0/X, y=1.0/Y; aux=1.0/(x-y);
	aux=aux/X; out=aux;
	if(aux-out>error) out++;
	cout << out << endl;
			
return 0;
}
