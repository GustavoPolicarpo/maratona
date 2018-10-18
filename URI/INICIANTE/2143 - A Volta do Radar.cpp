// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Volta do Radar
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2143

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
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
	int T, N, aux, out;
	while(scanf("%d", &T) and T){
		while(T--){
			scanf("%d", &N);
			if(N%2==0) out=(N-2)*2+2;
			else out=(N-1)*2+1;
			printf("%d\n", out);
		}
	}
	

	
	
return 0;
}
