// Author: Gustavo Policarpo
// Name: Turkish Roulette
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1485

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

const ll INF = 1LL << 52;

ll S, B, pd[515][130], rol[255], bal[130];
vector <ll> n;


ll solve(int r, int b, int fim){
	
	if(b==B) return 0;
	if(r>=fim) return -INF+2;
	
	if(pd[r][b]!=-INF) return pd[r][b];
	
	ll ret=solve(r+1, b, fim), aux=bal[b]*n[r];
	
	ret=max(ret, solve(r+2, b+1, fim)-aux);
	
	return pd[r][b]=ret;
	
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%lld %lld", &S, &B) and S){
		
		n.clear(); 
		
		rep(i, 0, S) scanf("%lld", &rol[i]);
		rep(i, 0, B) scanf("%lld", &bal[i]);
		
		n.pb(rol[S-1]+rol[0]);
		rep(i, 0, S-1) n.pb(rol[i]+rol[i+1]);
		rep(i, 0, S) n.pb(n[i]);
		
		ll ans=-INF;
		rep(i, 0, S){
			
			int fim=i+S-1;
			
			rep(j, i, fim+10) rep(k, 0, B+2) pd[j][k]=-INF;
			
			ans=max(ans, solve(i, 0, fim));
			
		}
		
		printf("%lld\n", ans);
		
	}
	
	return 0;
	
}
