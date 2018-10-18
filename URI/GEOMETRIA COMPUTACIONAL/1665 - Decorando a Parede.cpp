// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Decorando a Parede
// Nível: 6
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1665

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < ii, ii > iii;

vector <iii> in;
int n, w, h, rw, rh; 

bool check(int x, int y){
	if(x<0 || y<0) return false;
	if(x+rw>w || y+rh>h) return false;
	
	rep(i, 0, n){
		if(max(in[i].F.F, x) < min(in[i].S.F, x+rw) &&
			max(in[i].F.S, y) < min(in[i].S.S, y+rh) )
				return false;
	}
	//cout << x << "  " << y << '\n';
	return true;
}

void atualize(ii &ans, int x, int y){
	if(ans.S > y) ans = ii(x, y);
	if(ans.S == y) ans.F = min(ans.F, x);
}

set <int> sx, sy;
vector <int> cx, cy;

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//fflush(stdout);
	//cout.flush();
	
	int T; scanf("%d", &T);
	
	while(T--){
		scanf("%d %d %d", &n, &w, &h); int x1, x2, y1, y2; 
		in.clear(); sx.clear(), sy.clear(); cx.clear(), cy.clear();
		rep(i, 0, n){
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			in.pb(iii(ii(x1, y1), ii(x2, y2)));
		}
		
		rep(i, 0, n){
			if(!sx.count(in[i].F.F)){
				sx.insert(in[i].F.F);
				cx.pb(in[i].F.F);
			}
			if(!sx.count(in[i].S.F)){
				sx.insert(in[i].S.F);
				cx.pb(in[i].S.F);
			}
			if(!sy.count(in[i].F.S)){
				sy.insert(in[i].F.S);
				cy.pb(in[i].F.S);
			}
			if(!sy.count(in[i].S.S)){
				sy.insert(in[i].S.S);
				cy.pb(in[i].S.S);
			}
		}
		
		if(!sx.count(0)) cx.pb(0);
		if(!sy.count(0)) cy.pb(0);
		sort(cx.begin(), cx.end());
		sort(cy.begin(), cy.end());
		
		scanf("%d %d", &rw, &rh);
		
		bool yep = 0;
		rep(i, 0, cy.size()){
			if(cy[i]+rh>h) break;
			rep(j, 0, cx.size()){
				if(cx[j]+rw>w) break;
				if(check(cx[j], cy[i])){
					yep = true;
					printf("%d %d\n", cx[j], cy[i]);
					break;
				}
			}
			if(yep) break;
		}
		
		if(!yep) puts("Fail!");
		
	}	
	
	return 0;
}
