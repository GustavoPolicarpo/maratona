// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Brincadeira
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2659

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

const ll mod = 1e9+7;

int v[32];
int val[5000050];
int last[5000050];
int sum[5000050];

int main(){
	
	int N, T, A, X, Y; cin >> N >> T >> A >> X >> Y;
	rep(i, 0, T) cin >> v[i];
	
	val[0] = A, last[0] = -1;
	rep(i, 1, X+Y+20){
		int xr = 0; rep(j, 0, T) xr^=((val[i-1]&(1<<v[j]))!=0);
		val[i] = (val[i-1]>>1)|(xr<<(N-1)), last[i] = -1;
	}
	
	
	rep(i, 0, X+Y+20){
		sum[i] = val[i]; if(i) sum[i]+=sum[i-1]; sum[i]%=X;
		if(sum[i]==0 && i>=Y-1){
			printf("%d %d\n", 0, i);
			return 0;
		}
		
		if(last[sum[i]]==-1) last[sum[i]] = i;
		else{
			if(i-last[sum[i]] >= Y){
				printf("%d %d\n", last[sum[i]]+1, i);
				return 0;
			}
		}
	}
	
	puts("impossivel");
	
	return 0;
}
