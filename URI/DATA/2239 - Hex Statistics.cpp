// Author: Gustavo Policarpo
// Name: Hex Statistics
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2239

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001

#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < int, ii > iii;


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N; ll pd[1<<17], custo[1<<17];
ll fat[30], mod=1e9 + 7;

vector <string> n;

int C(char c){
	if(isdigit(c)) return c-'0';
	return c-'a'+10;
}

ll solve1(int mask){
	if(mask == (1<<16)-1) return 0;
	if(pd[mask]!=-1) return pd[mask];
	
	ll ret=ll(1)<<60, aux=0, sa;
	if(custo[mask]!=-1) aux=custo[mask];
	else{
		rep(i, 0, N){
			sa=0;
			rep(j, 0, n[i].size()){
				if(mask & (1<<C(n[i][j]))) continue;
				sa*=16;
				sa+=C(n[i][j]);
			}
			aux+=sa;
		}
		custo[mask]=aux;
	}

	rep(i, 0, 16){
		if(mask&(1<<i)) continue;
		ret=min(ret, aux+solve1(mask|(1<<i)));
	}
	return pd[mask]=ret;
}

ll solve2(int mask){
	if(mask == (1<<16)-1) return 0;
	if(pd[mask]!=-1) return pd[mask];
	
	ll ret=0, aux=0, sa;
	if(custo[mask]!=-1) aux=custo[mask];
	else{
		rep(i, 0, N){
			sa=0;
			rep(j, 0, n[i].size()){
				if(mask & (1<<C(n[i][j]))) continue;
				sa*=16;
				sa+=C(n[i][j]);
			}
			aux+=sa;
		}
		custo[mask]=aux;
	}
	
	rep(i, 0, 16){
		if(mask&(1<<i)) continue;
		ret=max(ret, aux+solve2(mask|(1<<i)));
	}
	return pd[mask]=ret;
}


ll solve3(int mask, int cnt){
	
	if(mask == (1<<16)-1) return 0;
	if(pd[mask]!=-1) return pd[mask];
	
	ll ret=0, aux=0, sa;
	if(custo[mask]!=-1) aux=custo[mask];
	else{
		rep(i, 0, N){
			sa=0;
			rep(j, 0, n[i].size()){
				if(mask & (1<<C(n[i][j]))) continue;
				sa*=16;
				sa+=C(n[i][j]);
			}
			aux+=sa;
		}
		custo[mask]=aux;
	}
	
	if(aux>=mod) aux%=mod;
	ret=(aux*fat[16-cnt]);
	if(ret>=mod) ret%=mod;
	
	rep(i, 0, 16){
		if(mask&(1<<i)) continue;
		ll rr=solve3(mask|(1<<i), cnt+1);
		ret+=rr;
		if(ret>=mod) ret%=mod;
	}
	
	if(ret>=mod) ret%=mod;
	return pd[mask]=ret;
}	

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	fat[0]=1;
	for(ll i=1; i<=20; i++)
		fat[i]=(fat[i-1]*i)%mod;
	memset(custo, -1, sizeof custo);
	
	scanf("%x", &N); string in;

	rep(i, 0, N){
		cin >> in;
		n.pb(in);
	}
	
	memset(pd, -1, sizeof pd);
	ll minimun=INF;
	rep(i, 0, 16)
		minimun=min(minimun, solve1(1<<i));
	
	memset(pd, -1, sizeof pd);	
	ll maximun=0;
	rep(i, 0, 16)
		maximun=max(maximun, solve2(1<<i));
	
	memset(pd, -1, sizeof pd);	
	ll somatorio=0;
	rep(i, 0, 16)
		somatorio=(somatorio+solve3(1<<i, 1))%mod;
	
		
	printf("%llx %llx %llx\n", minimun, maximun, somatorio);
		
return 0;

}
