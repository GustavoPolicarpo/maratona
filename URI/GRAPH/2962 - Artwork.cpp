// Author: Gustavo Policarpo
// Name: Artwork
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2962

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
 
 
struct use{
	ll x, y, r;
};
 
bool cmp(use a, use b){
	if(a.x!=b.x) return a.x < b.x;
	return a.y < b.y;
}
 
ll N, M, K;
vector <use> sensor;
int pset[10100];
 
int findset(int x){
	if(x!=pset[x]) pset[x] = findset(pset[x]);
	return pset[x];
}
 
void unionset(int x, int y){
	x = findset(x), y = findset(y);
	pset[x] = y;
}
 
bool check(){
	int t = sensor.size();
	
	rep(i, 0, t+10){
		pset[i] = i;
	}
	
	rep(i, 0, t){
		ll d1 = sensor[i].x - sensor[i].r;
		if(d1<=0.0) unionset(t+1, i);
		
		ll d2 = sensor[i].y + sensor[i].r;
		if(d2>=N) unionset(t+2, i);
		
		ll d3 = sensor[i].x + sensor[i].r;
		if(d3>=M) unionset(t+3, i);
		
		ll d4 = sensor[i].y - sensor[i].r;
		if(d4<=0) unionset(t+4, i);
	}
	
	rep(i, 0, t){
		rep(j, i+1, t){
			ll dst = ((sensor[i].x-sensor[j].x)*(sensor[i].x-sensor[j].x) + 
						(sensor[i].y-sensor[j].y)*(sensor[i].y-sensor[j].y));
			ll dstt = (sensor[i].r+sensor[j].r)*(sensor[i].r+sensor[j].r);
			if(dstt >= dst){
				unionset(i, j);
			}
			if((sensor[i].x-sensor[j].x)*(sensor[i].x-sensor[j].x) > dstt){
				//break;
			}
		}
		int a = findset(t+1), b = findset(t+2), c = findset(t+3), d = findset(t+4);
		if(a==d || a==c) return false;
		if(b==c || b==d) return false;
	}
	
	return true;
}
 
int main(){
	
	while(scanf("%lld %lld %lld", &M, &N, &K)!=EOF){
		
		sensor.clear(); use aux;
		rep(i, 0, K){
			scanf("%lld %lld %lld", &aux.x, &aux.y, &aux.r);
			sensor.pb(aux);
		}
		
		sort(sensor.begin(), sensor.end(), cmp);
		
		if(check()) puts("S");
		else puts("N");
		
	}
 
	return 0;
} 
