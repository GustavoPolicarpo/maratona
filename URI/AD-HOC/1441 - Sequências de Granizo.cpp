// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequências de Granizo
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1441

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;



int main()
{
	int H;
	while(scanf("%d", &H) and H!=0){
		int maior=H;
		while(H!=1){
			if(H%2==0)
				H/=2;
			else
				H=H*3+1;
			if(H>maior) maior=H;
		}
		printf("%d\n", maior);
	}
	
return 0;
}
