// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Torres de Hanói
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2251

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define MAXN 110
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair

using namespace std;

typedef pair <int, int> ii;
typedef long long int ll;

int ans;

int Hanoi(int n){
	return (1<<n) - 1;
}
int main(){
	
	int N, z=1;
	while(scanf("%d", &N) and N){
		printf("Teste %d\n", z++);
		printf("%d\n\n", Hanoi(N));
	}
	
	
	return 0;
}



