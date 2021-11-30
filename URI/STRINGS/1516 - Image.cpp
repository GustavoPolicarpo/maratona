// Author: Gustavo Policarpo
// Name: Image
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1516

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int N, M, A, B;
	while(scanf("%d %d", &N, &M) and N+M){
		char in[N][M];
		rep(i, 0, N)
			rep(j, 0, M)
				scanf(" %c", &in[i][j]);
		scanf("%d %d", &A, &B);
		int rl=A/N, rc=B/M;
		rep(i, 0, N)
			rep(j, 0, rl){
				rep(k, 0, M)
					rep(l, 0, rc)
						printf("%c", in[i][k]);
				printf("\n");
			}
		printf("\n")											;
	}
	
return 0;
}
