// Author: Gustavo Policarpo
// Name: Eleven
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1494

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < vector <int>, ii > iii;

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

char n[101]; int tam, np, ni, dig[10];
ll pd[10][60][12], fat[101], C[101][101];

ll fastexp(ll num,int base){
	
	ll x;
	
	if(base==0) return 1;	
	if(base==1) return num;

	if(base%2==0){
		x = fastexp(num,base/2)%mod;
		return (x*x)%mod;
	}
	else{
		return (num*fastexp(num,base-1))%mod;
	}
}

ll inverso(ll a){
  return fastexp(a,mod-2);
}

ll C_S(ll n, ll k){	
	if(n-k<0) return 0;
 	ll num, den, ret;
	num = fat[n];
	
	den= (fat[k] * fat[n - k]) % mod;
	
	den = inverso(den);
   
	ret = (num * den) % mod;

	return ret;
}

ll solve(int pos, int im, int pa, int si, int sp){
	
	if(pos==10) return sp%11==si%11;
	
	ll &p=pd[pos][im][si], ret=0;
	if(p!=-1) return p;
	
	rep(i, 0, 1+min(dig[pos], im)){
		if(dig[pos]-i>pa) continue;
		ll aux=( C[im][i] * C[pa][dig[pos]-i] )%mod;
		ret+=aux*solve(pos+1, im-i, pa-(dig[pos]-i), (si+i*pos)%11, (sp+(dig[pos]-i)*pos)%11);
		ret%=mod;
	}
	
	return p=ret;
}

int main()
{
	fat[0]=1; rep(i, 1, 101) fat[i]=(fat[i-1]*i)%mod;
	
	rep(i, 0, 101)
	rep(j, 0, 101)
		C[i][j]=C_S(i, j);
	
	while(scanf("%s", n) !=EOF){
		tam=strlen(n), np=tam/2, ni=tam-np;
		
		memset(dig, 0, sizeof dig);
		
		rep(i, 0, tam) dig[n[i]-'0']++;
		
		ll ans=0;
		rep(i, 1, 10){
					
			if(!dig[i]) continue;
			memset(pd, -1, sizeof pd);
			
			dig[i]--;
			ans+= (tam&1 ? solve(0, ni-1, np, i, 0) : solve(0, ni, np-1, 0, i));
			ans%=mod;
			dig[i]++;
					
		}
		
		printf("%lld\n", ans);
	}

	return 0;
	
}
