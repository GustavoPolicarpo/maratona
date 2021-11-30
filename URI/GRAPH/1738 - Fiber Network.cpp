// Author: Gustavo Policarpo
// Name: Fiber Network
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1738

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000

typedef long long int ll;
typedef pair < double, double > ii;
typedef pair < int, ii > iii;

int mat[205][205], N;
char s[205];

int main()
{
	while(scanf("%d", &N) and N){
		int u, v;
		memset(mat, 0, sizeof mat);
		while(scanf("%d %d", &u, &v) and u+v){
			u--, v--;
			scanf("%s", &s);
			rep(i, 0, strlen(s)){
				int t=s[i]-'a';
				mat[u][v]|=(1<<t);
			}
		}
		rep(k, 0, N)
		rep(i, 0, N)
		rep(j, 0, N)
			mat[i][j]|=mat[i][k]&mat[k][j];
		
		while(scanf("%d %d", &u, &v) and u+v){
			u--, v--;
			bool yep=false;
			rep(i, 0, 26){
				if(mat[u][v]&(1<<i)){
					yep=true;
					printf("%c", i+'a');
				}
			}
			if(!yep) printf("-");
			printf("\n");
		}
		printf("\n");
	}
	
return (0);
}
