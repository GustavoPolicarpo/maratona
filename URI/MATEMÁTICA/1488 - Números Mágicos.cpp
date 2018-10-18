// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Números Mágicos?
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1488

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;
 
//x =  ( n * m ) / ( 2*m + m^2 + 1)

int main()
{
	int n, z=1; 
	while(scanf("%d", &n) and n){
		int a, b, c, d, p1, p2, p3, p4, x;	
		int m=n/2;
		while(m>0){
			int up=n*m, den=2*m+m*m+1;
		//	cout << up << " " << den << endl;
			if(up%den==0){
				x=up/den;
				//cout << m << endl;
				break;
			}
			m--;
		}
		printf("Instancia %d\n", z++);
		if(m==0) printf("%d nao e quadripartido\n", n);
		else{
			p1=x-m, p2=x+m, p3=x/m, p4=x*m;
			printf("%d %d %d %d %d\n", m, p1, p2, p3, p4);
		} 
		printf("\n");
		
	}
	
		
return 0;
} 
