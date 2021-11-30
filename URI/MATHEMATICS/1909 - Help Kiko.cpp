// Author: Gustavo Policarpo
// Name: Help Kiko
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1909

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int arroz(int a, int b){
	return a*(b/__gcd(a, b));
}
int main()
{
	int N, T;
	while(scanf("%d %d", &N, &T) and N+T){
		int vet[N]; bool yep=true; set<int> num; 
		int mmc=1;
		rep(i, 0, N){
			scanf("%d", &vet[i]); num.insert(vet[i]);
			mmc=arroz(mmc, vet[i]);
			if(T%vet[i]!=0) yep=false;
		}	
		if(!yep){
			printf("impossivel\n");
			continue;
		}
		
		int out; yep=false;
		rep(i, 2, T+1){
			if(T%i!=0 || num.count(i)) continue;
			out=i;
			int aux=arroz(mmc, out);
			if(aux==T){
				yep=true;
				break;
			}
		}
	
		if(yep) printf("%d\n", out);
		else printf("impossivel\n");				
	}
	
return 0;
}
