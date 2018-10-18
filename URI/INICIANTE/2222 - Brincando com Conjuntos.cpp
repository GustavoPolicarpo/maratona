// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Brincando com Conjuntos
// Nível: 2
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2222

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



int main()
{
	int T, N, Q, aux; scanint(T);
	while(T--){
		scanint(N);
		ll n[N], ans, up=1; map<ll, int> e, ou;
		rep(i, 0, N){
			scanint(Q); n[i]=0;
			rep(j, 0, Q){
				scanint(aux);
				n[i]|=ll(up<<aux);
			}
		}
		int o, a, b;
		scanint(Q);
		rep(i, 0, Q){
			scanint(o), scanint(a), scanint(b);
			if(o==1){
				ans=n[a-1]&n[b-1]; aux=0;
				if(e.count(ans)) aux=e[ans];
				else{
					ll bk=ans;
					while(ans){
						aux+=(ans&1);
						ans/=2;
					}
					e[bk]=aux;
				}
				printf("%d\n", aux);
			}
			else{
				ans=n[a-1]|n[b-1]; aux=0;
				if(ou.count(ans)) aux=ou[ans];
				else{
					ll bk=ans;
					while(ans){
						aux+=(ans&1);
						ans/=2;
					}
					ou[bk]=aux;
				}
				printf("%d\n", aux);
			}
		}
				
	}
	

return 0;
}
