// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Bolinhas de Gude
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2877

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) cout << #a << " = " << a << " ---- " << #b << " = " << b << endl;
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int pd[101][101];

int solve(int i, int j){
	if(i==j || i==0 || j==0) return pd[i][j] = 10001;
	if(pd[i][j]!=-1) return pd[i][j];
	set <int> st;
	for(int k=1; k<=i; k++) st.insert(solve(i-k, j));
	for(int k=1; k<=j; k++) st.insert(solve(i, j-k));
	for(int k=1; k<=min(i, j); k++) st.insert(solve(i-k, j-k));
	int p = 0; set <int> :: iterator it;
	for(it=st.begin(); it!=st.end(); it++, p++){
		if(*it!=p)
			return pd[i][j] = p;
	}
	return pd[i][j] = st.size();
}

int main(){
	
	memset(pd, -1, sizeof pd);
	rep(i, 0, 101) rep(j, 0, 101) solve(i, j);
	
	/*rep(i, 0, 10) rep(j, 0, 10){
		if(j==0) puts("");
		cout << pd[i][j] << " ";
	}*/
	
	int n; scanf("%d", &n); int ans = 0, x, y;
	rep(i, 0, n){
		scanf("%d %d", &x, &y);
		if(pd[x][y]==10001){
			puts("Y");
			return 0;
		}
		ans ^= pd[x][y];
	}
	
	if(ans) puts("Y");
	else puts("N");
	
	return 0;
} 
