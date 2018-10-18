// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Angariando Fundos
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2700

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < ii, ll > iii;


ll bit[100010];
map <ii, ll> mapa;
map <ii, ll> :: iterator it;
map <int, int> C;
vector <iii> v;
vector <int> vv;
vector <iii> vaux;

ll query(int x){
	ll ret = 0;
	for(; x>0; x-=x&-x) ret = max(ret, bit[x]);
	return ret;
}

void update(int x, ll val){
	for(; x<100010; x+=x&-x) bit[x] = max(bit[x], val);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N; scanf("%d", &N);
	int b, f, d;
	
	rep(i, 0, N){
		scanf("%d %d %d", &b, &f, &d);
		vaux.pb(iii(ii(b, f), d));
		vv.pb(f);
	}
	
	int cnt = 1;
	sort(vv.begin(), vv.end());
	rep(i, 0, vv.size()) if(!C.count(vv[i])) C[vv[i]] = cnt++;
	
	rep(i, 0, vaux.size()){
		iii aux = vaux[i];
		b = aux.F.F, f = aux.F.S, d = aux.S;
		f = C[f];
		mapa[ii(b, f)]+=d;
	}
	
	for(it=mapa.begin(); it!=mapa.end(); it++) v.pb(iii(it->first, it->second));
	
	sort(v.begin(), v.end());
	
	vaux.clear();
	int last = -1;
	
	rep(i, 0, v.size()){
		iii aux = v[i];
		if(aux.F.F!=last){
			rep(j, 0, vaux.size()) update(vaux[j].F.S, vaux[j].S);
			vaux.clear();
		}
		last = aux.F.F;
		ll xua = query(aux.F.S-1);
		vaux.pb(iii(aux.F, aux.S+xua));
	}
	
	rep(j, 0, vaux.size()) update(vaux[j].F.S, vaux[j].S);
	
	printf("%lld\n", query(100005));
	
	return 0;
}
