// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Banco
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2425

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int n, c, ans=0;
	
	cin >> n >> c;
	vector <ii> in;
	rep(i, 0, c){
		ii aux; cin >> aux.F >> aux.S;
		in.pb(aux);
	}
	
	priority_queue <int> pq;
	rep(i, 0, min(n, c)){
		pq.push(-(in[i].F+in[i].S));
	}
	
	rep(i, 0+n, c){
		int t=-pq.top(); pq.pop();
		///cout << t << '\n';
		if(t-in[i].F > 20){
			ans++;
			pq.push(-(t+in[i].S));
		}
		else if(t-in[i].F<0){
			pq.push(-(in[i].F+in[i].S));
		}
		else{
			pq.push(-(t+in[i].S));
		}
	}
	
	cout << ans << '\n';

	return 0;
}
