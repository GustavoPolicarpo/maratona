// Author: Gustavo Policarpo
// Name: It's a Trap Bino
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2481

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

#define INF 0x3f3f3f3f

typedef long long int ll;
typedef pair < ll, ll > ii;

const ll LINF = 1LL << 60;

void scanint(ll &x)
{
    register ll ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57) );ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

const int MAXV=100010;
ii n[MAXV];
ll best[MAXV], go;

struct hux{
	ll a, b;
	int id;
};

ll B(ll a, ll b){
	return b - a*a;
}

bool cross(hux a, hux b, hux c){
	return (c.b-a.b)*(a.a-b.a) < (b.b-a.b)*(a.a-c.a);
}

int main()
{	
	
	//freopen("in.txt", "r", stdin);
	
	int Q, N, pointer, began; 
	
	scanf("%d", &Q);
	
	while(Q--){
		
		scanf("%d", &N);
		
		rep(i, 0, N) scanint(n[i].F), scanint(n[i].S), n[i].S*=-1;
		
		vector <hux> v; hux aux; pointer = 0, began = 1;
		if(n[0].F == 0) aux.a = n[1].F, aux.b = B(n[1].F, n[1].S), aux.id=1, began++;
		else aux.a = n[0].F, aux.b = B(n[0].F, n[0].S), aux.id=0;
		v.pb(aux);
		
		rep(i, began, N){
			
			if(pointer >= v.size()) pointer = v.size()-1;
			
			ll x = n[i].F;
			while(pointer < v.size()-1 
			&& v[pointer+1].a*x+v[pointer+1].b > v[pointer].a*x+v[pointer].b) pointer++;
			
			best[i] = max(n[i].S, v[pointer].a*x + v[pointer].b + n[i].S);
			aux.a=n[i].F, aux.b=B(n[i].F, best[i]), aux.id=i;
			v.pb(aux);
			
			while(v.size()>=3){
				hux a=v[v.size()-3], b=v[v.size()-2], c=v[v.size()-1];
				if(cross(a, b, c)) v.erase(v.end()-2);
				else break;
			}
			
		}
		
		ll ans=best[N-1];
		if(ans<=0) printf("Perde %lld\n", abs(ans));
		else printf("Ganha %lld\n", ans);
		
	}
	
	return 0;
	
}
