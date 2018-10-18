// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Falha Ao Cercar Legumes
// Nível: 7
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2007

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


struct use{
	int x, yi, yf, t;	
};

bool cmp(use a, use b){
	return a.x < b.x;
}

int P, V;
vector <ii> vy; map<int, int> mapa1, mapa2;
vector <ii> planta;
vector <ii> cerca;
vector <use> v;

const int MAX = 600060*3;
int tree[MAX], lazy[MAX];

void propagate(int no, int i, int j){
	if(lazy[no]){
		tree[no]^=1;
		if(i!=j){
			lazy[no*2]^=1;
			lazy[no*2+1]^=1;
		}
		lazy[no]=0;
	}
}

void update(int no, int i, int j, int a, int b){
	propagate(no, i, j);
	if(i>j || i>b || j<a) return;
	
	if(i>=a && j<=b){
		lazy[no]^=1;
		propagate(no, i, j);
		return;
	}
	
	int L=no*2, R=L+1, mid=(i+j)/2;
	update(L, i, mid, a, b);
	update(R, mid+1, j, a, b);
	
	//tree[no] = tree[L]+tree[R];
}

int query(int no, int i, int j, int a){
	if(i>j || i>a || j<a) return 0;
	propagate(no, i, j);
	
	if(i==j && i==a) return tree[no];
	
	int L=no*2, R=L+1, mid=(i+j)/2;
	return query(L, i, mid, a)+query(R, mid+1, j, a);
}

bool mysort(ii a, ii b){
	if(a.F!=b.F) return a.F<b.F;
	return a.S<b.S;
}

int main(){
	
	scanf("%d %d", &P, &V); ii aux; use xua;
	
	rep(i, 0, P){
		scanf("%d %d", &aux.F, &aux.S);
		vy.pb(ii(aux.S, 1));
		planta.pb(aux);
	}
	
	rep(i, 0, V){
		scanf("%d %d", &aux.F, &aux.S);
		vy.pb(ii(aux.S, 0));
		cerca.pb(aux);
	}	cerca.pb(cerca[0]);
	
	sort(vy.begin(), vy.end(), mysort); int cnt = 1;
	
	rep(i, 0, vy.size()){
		if(vy[i].S){
			if(!mapa2.count(vy[i].F))
				mapa2[vy[i].F]=cnt++;
		}else{
			if(!mapa1.count(vy[i].F))
				mapa1[vy[i].F]=cnt++;
		}
	}
	
	rep(i, 0, P){
		xua.t=1, xua.yf=i+1;
		xua.x=planta[i].F, xua.yi=mapa2[planta[i].S];
		v.pb(xua);
	}
	
	rep(i, 0, V){
		if(cerca[i].F==cerca[i+1].F){
			xua.t=0, xua.x=cerca[i].F;
			xua.yi=mapa1[cerca[i].S], xua.yf=mapa1[cerca[i+1].S];
			if(xua.yi>xua.yf) swap(xua.yi, xua.yf);
			v.pb(xua);
		}
	}
	
	sort(v.begin(), v.end(), cmp);
	
	ll ans = 0;
	rep(i, 0, v.size()){
		xua = v[i];
		//cout << xua.t << " " << xua.x << " " << xua.yi << " " << xua.yf << '\n';
		if(xua.t){
			int yep = query(1, 0, cnt, xua.yi);
			if(!yep) ans+=xua.yf;
		}else{
			update(1, 0, cnt, xua.yi, xua.yf);
		}
	}
	
	printf("%lld\n", ans);
	
	
	return 0;
}

