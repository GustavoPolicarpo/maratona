// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tornado!
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1266

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
	int N;
	while(scanf("%d", &N) && N){
		int c1=0, c2=0, n[N+2];
		rep(i, 1, N+1)
			scanf("%d", &n[i]);
		n[0]=n[N];
		n[N+1]=n[1];
			
		rep(i, 1, N+1){
			if(n[i]==0 && n[i-1]==0){
				c1++, i++;	
			}			
		}
		
		reo(i, N, 0){
			if(n[i]==0 && n[i+1]==0){
				c2++, i--;	
			}			
		}
		
		printf("%d\n", min(c1,c2));
	}	
return 0;
}
