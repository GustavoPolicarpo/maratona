// Author: Gustavo Policarpo
// Name: Sun Bath in The Garden
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2110

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
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

int main()
{	
	int N, L, D;
	while(scanf("%d %d %d", &N, &L, &D) !=EOF){
		double n[N], j, sum=0;
		rep(i, 0, N){
			scanf("%lf", &n[i]);
			if(n[i]==0) j=i;
		}
		double e=0.0, d=0.0, aux, tg, out;
		sum=L+D;
		for(int i=j-1; i>=0; i--){
			aux=atan(n[i]/sum);
			if(aux>e) e=aux;
			sum+=L+D;	
		}
		sum=L+D;
		for(int i=j+1; i<N; i++){
			aux=atan(n[i]/sum);
			if(aux>d) d=aux;
			sum+=L+D;	
		}
		
		d*=180.0/M_PI, e*=180.0/M_PI;
		tg=180.0-d-e;
		out=16.0/3.0*tg;
		printf("%.2lf\n", out);				
	}

return 0;
}
