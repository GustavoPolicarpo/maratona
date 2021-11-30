// Author: Gustavo Policarpo
// Name: Dynamic Frog
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1054

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

void scanint(ll &x)
{
    register ll ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	
	rep(z, 1, T+1){
		int N, D; cin >> N >> D;
		
		vector <ii> n; char t; ii aux;
		n.pb(mp(0, 2));
		rep(i, 0, N){
			cin >> t;
			if(t=='S') aux.S=1;
			else aux.S=2;
			cin >> t >> aux.F;
			n.pb(aux);
		}
		n.pb(mp(D, 2));
		
		int out=0, take=1, p=0;
		
		for(int i=0; i<=N; i++){
			//cout << p << " " << n[i+1].F << '\n';
			if(n[i+1].S==1){
				if(take){
					n[i+1].S=0;
					out=max(out, n[i+1].F-p);
					p=n[i+1].F;
					take=0;
				}
				else take=1;
			}
			else{
				out=max(out, n[i+1].F-p);
				p=n[i+1].F;
			}
		}
		
		p=n[N+1].F; take=1;
		for(int i=N+1; i>0; i--){
			//cout << p << " " << n[i-1].F << '\n';
			if(n[i-1].S==1 && take){
				n[i-1].S=0;
				out=max(out, p-n[i-1].F);
				p=n[i-1].F;
			}
			else if(n[i-1].S==0) take=1;
			else{
				out=max(out, p-n[i-1].F);
				p=n[i-1].F;
			}
		}
		
		printf("Case %d: %d\n", z, out);
		
	}
	
	return 0;
	
}
