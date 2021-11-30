// Author: Gustavo Policarpo
// Name: Space Elevator
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1226

#include <bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;

char n[20];
ull pd[20][2][2][2], p;

ull solve(int i, int one, int pas, int m){
	
	if(i==p) return pas;
	if(pd[i][one][pas][m]!=-1) return pd[i][one][pas][m];
	ull ret=0;
	
	if(m)
		rep(j, 0, 10){
			if(j==1) ret+=solve(i+1, 1, pas, 1);
			else if(j==4) ret+=solve(i+1, 0, 1, 1);
			else if(j==3){
				if(one) ret+=solve(i+1, 0, 1, 1);
				else ret+=solve(i+1, 0, pas, 1);
			}
			else ret+=solve(i+1, 0, pas, 1);
		}
	else
		rep(j, 0, n[i]+1-'0'){
			if(j==1) ret+=solve(i+1, 1, pas, 1-(j==n[i]-'0'));
			else if(j==4) ret+=solve(i+1, 0, 1, 1-(j==n[i]-'0'));
			else if(j==3){
				if(one) ret+=solve(i+1, 0, 1, 1-(j==n[i]-'0'));
				else ret+=solve(i+1, 0, pas, 1-(j==n[i]-'0'));
			}
			else ret+=solve(i+1, 0, pas, 1-(j==n[i]-'0'));
		}
		
	return pd[i][one][pas][m]=ret;
	
}
int main(){
	
	ull N;
	while(scanf("%llu", &N) !=EOF){
		ull ini=1, fim=-1, ans;
		while(ini<=fim){
			
			ull use=(ini/2+fim/2) + (ini&1 && fim&1), aux=use;
			p=0; memset(pd, -1, sizeof pd);
			
			while(aux){
				n[p++]=aux%10+'0';
				aux/=10;
			}	n[p]='\0';
			reverse(n, n+p);
			
			aux=solve(0, 0, 0, 0);
			aux=use-aux;
			
			if(aux==N){
				ans=use;
				fim=use-1;
			}
			if(aux<N) ini=use+1;
			else fim=use-1;
		}
		
		printf("%llu\n", ans);
		
	}
	
	return 0;
	
}
