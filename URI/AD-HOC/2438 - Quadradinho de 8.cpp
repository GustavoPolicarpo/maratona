// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quadradinho de 8
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2438

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

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


int n[1000010];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N; cin >> N;
	int cnt[8], sum=0; 
	memset(cnt, 0, sizeof cnt); 
	cnt[0]=1;
	ll ans=0;
	
	rep(i, 0, N) scanint(n[i]);
	
	rep(i, 0, N){
		sum+=n[i];
		sum%=8;
		
		ans+=cnt[sum];
		cnt[sum]++;
	}
	
	printf("%lld\n", ans);
	
	return 0;
	
}
