// Author: Gustavo Policarpo
// Name: Parking Lot
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1246

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
	int N, C, P, Q, total;
	char op;
	while(scanf("%d %d", &C, &N) !=EOF){
		map <int, ii> est; total=0; int e[C];
		memset(e, 0, sizeof e);
		rep(i, 0, N){
			scanf(" %c %d", &op, &P);
			if(op=='C'){
				scanf("%d", &Q);
				int ce=0;
				rep(j, 0, C){
					if(e[j]==0) ce++;
					else ce=0;
					if(ce==Q){
						rep(k, j-Q+1, j+1) e[k]=1;
						est[P]=mp(j-Q+1, j);
						total+=10;
						break;						
					}
				}
			}
			else{
				ii aux;
				aux=est[P];
				rep(j,aux.F, aux.S+1) e[j]=0;
			}	
		}
		printf("%d\n", total);
	}


return 0;
}
