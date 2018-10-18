// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: 3-RSA
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2636

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

//typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

//Encontra um fator primo de N

ll pollard_r, pollard_n;

ll f(ll val){return (val*val+pollard_r)%pollard_n; }

ll myabs(ll a){return a >= 0 ? a:-a; }

ll pollard(ll n){
    srand(unsigned(time(0)));
    pollard_n = n;
    ll d = 1;
    do {
        d = 1;
        pollard_r = rand()%n;
        ll x = 2, y = 2;
        while(d == 1)
            x = f(x), y = f(f(y)), d = __gcd(myabs(x-y), n);
    } while(d == n);
    return d;
}

bool isPrime(ll n){
	if(n==2) return true;
	if(n%2==0) return false; ll fim = sqrt(n);
	for(int i=3; i<=fim; i+=2) if(n%i==0){
		return false;
	}	return true;
}

int main()
{
	//ios_base::sync_with_stdio(false);

	ll n;
	
	while(scanf("%lld", &n)!=EOF){
		if(!n) break;
		
		vector <ll> v; ll aux, nn = n;
		
		ll fim = powl(n, 1.0/3.0);
		rep(i, 2, fim+1){
			if(n%i==0){
				v.pb(i);
				n/=i;
				break;
			}
		}
		
		fim = powl(n, 1.0/2.0);
		rep(i, 2, fim+1){
			if(n%i==0){
				v.pb(i);
				n/=i;
				v.pb(n);
				break;
			}
		}
		
		v.pb(n); sort(v.begin(), v.end());
		
		printf("%lld = %lld x %lld x %lld\n", nn, v[0], v[1], v[2]);
		
		
	}


	return 0;
}

