// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Palíndrome
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2285

# include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F

typedef long long ll;
typedef pair < int, int>  ii;

char n[2020]; int N, z=1;
int pd[2020];
vector <int> m[2020];

int solve(int i){
	if(i>=N) return 0;
	if(pd[i]!=-1) return pd[i];
	int ret=INF;
	rep(j, 0, m[i].size()){
		ret=min(ret, solve(i+m[i][j])+1);
	}
	
	return pd[i]=ret;
}
int main(){
	while(scanf("%d", &N) and N){
		printf("Teste %d\n", z++);
		scanf("%s", n);
		rep(i, 0, N){
			m[i].clear();
			pd[i]=-1;
			for(int j=N-1; j>=i; j--){
				int ini=i, fim=j;
				while(ini<fim){
					if(n[ini]==n[fim]) ini++, fim--;
					else break;
				}
				if(ini==fim){
					m[i].pb((ini-i)*2+1);
				}
				else if(ini>fim){
					m[i].pb((ini-i)*2);
				}
			}
		}
		
		/*rep(i, 0, N){
			rep(j, 0, m[i].size())
				cout << m[i][j] << " ";
			cout << endl;
		}*/
		
		printf("%d\n\n", solve(0));
	}

	return 0;
}

