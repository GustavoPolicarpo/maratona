// Author: Gustavo Policarpo
// Name: Tetris
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2250

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

struct g{
	int pt[12], tt; string nome;
	
};

bool comp(g a, g b){
	if(a.tt>b.tt) return true;
	if(b.tt>a.tt) return false;
	if(a.nome>b.nome) return false;
	return true;
}
int main(){
	int N, z=1;
	while(scanf("%d", &N) and N){
		printf("Teste %d\n", z++);
		g n[N];
		rep(i, 0, N){
			cin >> n[i].nome;
			int m=1001, M=-1; n[i].tt=0;
			rep(j, 0, 12){
				scanf("%d", &n[i].pt[j]); n[i].tt+=n[i].pt[j];
				if(n[i].pt[j]>M) M=n[i].pt[j];
				if(n[i].pt[j]<m) m=n[i].pt[j];	
			}
			n[i].tt-=(m+M);
		}
		sort(n, n+N, comp);
		int cnt=1;
		printf("%d %d ", 1, n[0].tt); cout << n[0].nome << '\n';
		rep(i, 1, N){
			int aux=i+1;
			if(n[i].tt==n[i-1].tt) aux=cnt;
			else cnt=i+1;
			printf("%d %d ", aux, n[i].tt); cout << n[i].nome << '\n';
		}
		printf("\n");
	}
	
	
	return 0;
}



