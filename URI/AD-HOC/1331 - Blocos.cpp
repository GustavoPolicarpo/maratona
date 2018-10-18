// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Blocos
// Nível: 6
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1331

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

int n, pd[202][202][202];
int tam[202], col[202], v[202];

int solve(int i, int j, int t){
	
	int aux=t+tam[i]; aux=aux*aux;
	
	if(i==j) return aux;
	int &dp=pd[i][j][t];
	if(dp!=-1) return dp;
	
	dp=max(solve(i+1, j, 0)+aux, solve(i, j-1, t)+tam[j]*tam[j]);
	if(col[i]==col[j]) dp=max(dp, solve(i, j-1, t+tam[j]));
	
	rep(k, i+2, j){
		if(col[i]==col[k]){
			dp=max(dp, solve(i, k-1, t+tam[k])+solve(k+1, j, 0));
		}
	}
	
	return dp;
	
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T, z=1; cin >> T;
	
	rep(z, 1, T+1){
		
		scanf("%d", &n);
		rep(i, 0, n){
			rep(j, 0, n)
			rep(k, 0, n)
				pd[i][j][k]=-1;
			scanf("%d", &v[i]);
		}
		
		int i=0, p=0;
		tam[p]=1, col[p]=v[i++];
		
		while(i<n){
			
			if(v[i]==col[p]) tam[p]++;
			else{
				p++;
				tam[p]=1;
				col[p]=v[i];
			}
			i++;
		}	
		
		//rep(i, 0, p+1) cout << tam[i] << " ";
		
		printf("Case %d: %d\n", z, solve(0, p, 0));
		
	}
	
	
	return 0;
	
}
