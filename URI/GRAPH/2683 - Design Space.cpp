// Author: Gustavo Policarpo
// Name: Design Space
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2683

#include<bits/stdc++.h>
#define gc getchar
 
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
typedef pair<int, ii> iii;

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

const ll mod = 1000000007;


vector <iii> edg;
int pset[1000010];

int findset(int x){
	if(x!=pset[x]) pset[x] = findset(pset[x]);
	return pset[x];
}
void unionset(int x, int y){
	x = findset(x), y = findset(y);
	pset[x] = y;
}
bool sameset(int x, int y){
	return findset(x)==findset(y);
}

int main(){
	
	int N; scanint(N);
	int u, v, c, mr = 0, ans1 = 0, ans2 = 0;
	
	rep(i, 0, N){
		scanint(u), scanint(v), scanint(c); mr = max(mr, max(u, v));
		edg.pb(iii(c, ii(u, v)));
	}
	
	sort(edg.begin(), edg.end());
	rep(i, 1, mr+1) pset[i] = i;
	rep(i, 0, edg.size()){
		u = edg[i].S.F,
		v = edg[i].S.S,
		c = edg[i].F;
		if(!sameset(u, v)){
			unionset(u, v);
			ans1+=c;
		}
	}
	reverse(edg.begin(), edg.end());
	rep(i, 1, mr+1) pset[i] = i;
	rep(i, 0, edg.size()){
		u = edg[i].S.F,
		v = edg[i].S.S,
		c = edg[i].F;
		if(!sameset(u, v)){
			unionset(u, v);
			ans2+=c;
		}
	}
	
	printf("%d\n%d\n", ans2, ans1);
				
	return 0;
}
