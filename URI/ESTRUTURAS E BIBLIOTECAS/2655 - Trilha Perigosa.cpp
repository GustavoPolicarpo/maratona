// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Trilha Perigosa
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2655

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


int N, M, Q, n[100010];
int bit[100010][55];

void update(int x, int t, int v){
	while(x<=N+2){
		bit[x][t]+=v;
		x+=x&-x;
	}
}

int query(int x, int t){
	int ret = 0;
	while(x>0){
		ret+=bit[x][t];
		x-=x&-x;
	}
	return ret;
}

int main(){
	
	scanf("%d %d %d", &N, &Q, &M);
	
	rep(i, 1, N+1){
		scanf("%d", &n[i]);
		update(i, n[i], 1);
	}
	
	int a, b, c;
	while(Q--){
		scanf("%d %d %d", &c, &a, &b);
		if(c==2){
			update(a, b, 1);
			update(a, n[a], -1);
			n[a] = b;
		}else{
			int ans = 0;
			rep(i, 1, M+1){
				int aux = query(b, i) - query(a-1, i);
				if(aux) ans++;
			}
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
