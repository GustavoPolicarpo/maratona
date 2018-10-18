// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Altas Aventuras
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2383

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


const int MAXN = sqrt(1e10) + 1;
ll C[MAXN + 2][35];

void build_rec(int n){
	n=sqrt(n) + 2;
	C[0][0]=1;
	rep(i, 1, n+1){
		C[i][0]=C[i][i]=1;
		rep(j, 1, 32){
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	return ;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, k; cin >> n >> k;
	
	if(k==1){
		printf("%d\n", n);
		return 0;
	}
	
	if(k > 32) k = 32;
	
	build_rec(n);
	
	int i=1;
	while(1){
		ll soma=0;
		rep(j, 1, k+1) soma+=C[i][j];
		if(soma >= n){
			printf("%d\n", i);
			break;
		}
		i++;
	}
	
	return 0;
	
}
