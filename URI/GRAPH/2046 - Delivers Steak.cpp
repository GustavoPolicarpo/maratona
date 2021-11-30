// Author: Gustavo Policarpo
// Name: Delivers Steak
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2046

#define gc getchar_unlocked
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
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}


int dPT(ii a, ii b)
{
	return abs(a.F-b.F)+abs(a.S-b.S);
}

int main()
{
	int N, M, K, L, z=1;
	while(scanf("%d %d", &N, &M)){
		if(N==0||M==0) break;
		if(z>1) printf("\n");
		
		scanint(K);
		
		vector <ii> sedes;
		ii aux;
		rep(i, 0, K){
			//scanf("%d %d", &aux.F, &aux.S);
			scanint(aux.F), scanint(aux.S);
			sedes.pb(aux);
		}
		sort(sedes.begin(), sedes.end());
		
		scanint(L);
		
		printf("Instancia %d\n", z++);
		rep(i, 0, L){
			scanint(aux.F), scanint(aux.S);
			int md=INF, pos;
			rep(j, 0, K){
				int dist=dPT(aux, sedes[j]);
				if(dist<md)
					md=dist, pos=j;
			}
			printf("%d %d\n", sedes[pos].F, sedes[pos].S);		
		}			
	}
		
return 0;
}
