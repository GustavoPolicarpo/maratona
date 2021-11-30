// Author: Gustavo Policarpo
// Name: Red Lights
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2480

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

vector <ii> mat[22];

bool cmp(ii a, ii b){
	if(a.S!=b.S) return a.S > b.S;
	return a.F > b.F;
}

int solve(int n, int m){
	
	int ret=0;
	
	rep(j, 0, m){
		int ordenado=1;
		do{
			ordenado=1;
			rep(i, 0, n-1){
				if(cmp(mat[i][j], mat[i+1][j])){
					ordenado=0;
					ret++;
					swap(mat[i], mat[i+1]);
				}
			}
		}while(!ordenado);
	}
	
	return ret;
	
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int z=1, n, m;
	
	while(scanf("%d %d", &n, &m) != EOF){
		if(z-1) printf("\n");
		printf("Instance %02d:\n", z++);
		int v; char op;
		ll red=0;
		rep(i, 0, n){
			mat[i].clear();
			rep(j, 0, m){
				scanf(" [%d]%c", &v, &op);
				mat[i].pb(mp(0, 0));
				
				mat[i][j].F=v;
				if(op=='S') mat[i][j].S=0;
				else if(op=='G') mat[i][j].S=1;
				else if(op=='W') mat[i][j].S=2;
				else if(op=='R') mat[i][j].S=3, red=red+v;
			}
		}
		
		int move=solve(n, m);
		
		printf("%d %lld\n", move, red);
		
	}
	
	return 0;
}
