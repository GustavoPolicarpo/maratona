// Author: Gustavo Policarpo
// Name: Rescue in Free Fall
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1552

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;

vector < iii > edg;
int pset[501];

int findset(int u)
{
	if(pset[u]!=u)
		pset[u]=findset(pset[u]);
	return pset[u];
	
}
void unionset(int x, int y)
{
	x=findset(x); y=findset(y);
	if(x==y) return;
	pset[x]=y;
}
bool sameset(int x, int y)
{
	return findset(x) == findset(y);
}

int main(){
    int T; cin >> T;
    while(T--){
	
	edg.clear();
    	int n; cin >> n; 
    	ii p[n+1];
    	
    	int x, y;
    	rep(i, 0, n){
    		cin >> x >> y;
    		p[i]=mp(x, y);
		}
		
		int x1, x2, y1, y2; double d;
		rep(i, 0, n){
			x1=p[i].F; y1=p[i].S;
			rep(j, i+1, n){
				x2=p[j].F; y2=p[j].S;
				d=sqrt(pow(x2-x1,2)+pow(y2-y1,2));
				edg.pb(mp(d , mp(i, j)));
				//edg.pb(mp(d , mp(j, i)));	
			}
		}
		
		sort(edg.begin(), edg.end());
		
		rep(i, 0, n+1)
			pset[i]=i;
							
		ii aux; double mst=0;
		rep(i, 0, edg.size()){
			d=edg[i].F;
			aux=edg[i].S;
			x=aux.F; y=aux.S;
			if(!sameset(x , y)){
				unionset(x, y);
				mst+=d;
			}
		}
		
		mst/=100.0;
		cout << fixed << setprecision(2) << mst << endl;	
	}
	
return 0;
}
