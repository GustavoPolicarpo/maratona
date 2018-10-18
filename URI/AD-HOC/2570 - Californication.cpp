// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Californication
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2570

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

#define INF 0x3f3f3f3f
const int mod=1e9+7;

ii l[1010], c[1010];
int ans[4];

int main(){

	int N, M, K; cin >> N >> M >> K;
	
	char t; int p, s=0;
	rep(i, 1, K+1){
		scanf(" %c %d", &t, &p);
		if(t=='L') l[p]=mp(s, i);
		else c[p]=mp(s, i);
		s++; if(s==4) s=0;
	}
	
	rep(i, 1, N+1){
		rep(j, 1, M+1){
			if(l[i].S && !c[j].S) ans[l[i].F]++;
			else if(!l[i].S && c[j].S) ans[c[j].F]++;
			else if(l[i].S && c[j].S){
				if(l[i].S>c[j].S) ans[l[i].F]++;
				if(l[i].S<c[j].S) ans[c[j].F]++;
			}
		}
	}
	
	printf("R%d H%d C%d P%d\n", ans[0], ans[1], ans[2], ans[3]);
    
    return 0;
     
}
