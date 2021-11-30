// Author: Gustavo Policarpo
// Name: Beverly Hills, Century City
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1810

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


struct dias{
	int cp, u, e, d;
};

int N;
ll dtt, pd[200], dem[200]; 
dias n[200]; 

ll solve(int i)
{
	if(i==N) return 0;
	if(pd[i]!=-1) return pd[i];
	
	ll ret=0, ans=INF;
	rep(j, i+1, N+1){
		ll aux;
		if(i>0) aux=dem[j-1]-dem[i-1];
		else aux=dem[j-1];
		ll sum=0;
		rep(k, i, j-1){
			sum+=(aux-n[k].d)*n[k].e;
			aux-=n[k].d;
		}
		if(i>0) ans=min(ans, solve(j) + n[i].cp + n[i].u*(dem[j-1]-dem[i-1]) + sum);
		else ans=min(ans, solve(j) + n[i].cp + n[i].u*(dem[j-1]) + sum);
		
		ret=ans;
	}
	
	return pd[i]=ret;
}
int main()
{
	int z=1;
	while(scanf("%d", &N) and N){
		memset(pd, -1, sizeof pd); dtt=0;
		rep(i, 0, N){
			scanf("%d %d %d %d", &n[i].cp, &n[i].u, &n[i].e, &n[i].d);
			dtt+=n[i].d;
			if(i==0) dem[0]=n[0].d;
			else dem[i]=dem[i-1]+n[i].d;
		}
		dem[N]=dtt;
		ll out=solve(0);
		printf("Instancia #%d\n%lld\n\n",z++, out);
	}
	
return 0;
}
