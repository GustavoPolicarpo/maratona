// Author: Gustavo Policarpo
// Name: Matrix of Squares
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1578

#include<bits/stdc++.h>

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
#define MAXV 100001
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int main()
{
	//freopen("out.txt", "w", stdout);
	int N, z=4; scanf("%d", &N);
	while(N--){
		if(z>4) printf("\n");
		int M; scanf("%d", &M);
		ull mat[M][M], maior[M], aux;
		memset(maior, 0, sizeof maior);
		rep(i, 0, M)
			rep(j, 0, M){
				cin >> aux;
				mat[i][j]=aux*aux;
				if(mat[i][j]>maior[j])
					maior[j]=mat[i][j];
			}
		int esp[M];
		memset(esp, 0, sizeof esp);
		rep(i, 0, M)
			while(maior[i]>=1)
				maior[i]/=10, esp[i]++;		
		printf("Quadrado da matriz #%d:\n", z++);
		rep(i, 0, M){
			rep(j, 0, M){
				cout << setw(esp[j]) << mat[i][j];
				if(j<M-1) cout << " ";
			}
			cout << endl;
		}	
	}
return 0;
}
