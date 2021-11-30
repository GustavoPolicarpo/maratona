// Author: Gustavo Policarpo
// Name: Board With Prizes
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1543

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F

typedef pair < int, int > ii;
typedef long long int ll;


int pd[101][101], mat[101][101];
char op[101][101];
int N, M, K;
set <ii> adj;


int solve(int i, int k)
{
	if(i==N) return 0;
	if(pd[i][k]!=-1) return pd[i][k];
	
	int sum=0;
	rep(j, 0, M){
		if(op[k][j]=='-') sum-=mat[i][j];
		else if(op[k][j]=='+') sum+=mat[i][j];	
	}
	
	int ret=-1000000;
	rep(j, 0, K)
		if(adj.count(mp(k,j)))	
			ret=max(ret,solve (i+1, j)+sum);
			
	return pd[i][k]=ret;			
}

int main ()
{
	while(scanf("%d %d", &N, &M) and N+M){
		memset(pd, -1, sizeof pd);
		rep(i, 0, N)
			rep(j, 0, M)
				scanf("%d", &mat[i][j]);
		scanf("%d", &K); adj.clear();
		rep(i, 0, K)
			rep(j, 0, M)
				scanf(" %c", &op[i][j]);
		
		rep(i, 0, K)
			rep(j, i, K){
				bool lig=true;
				rep(k, 0, M){
					if(op[i][k]==op[j][k] && op[i][k]!='.'){
						lig=false;
						break;
					}
				}
				if(lig)
					adj.insert(mp(i,j)), adj.insert(mp(j,i));			
			}
				
		int out=-100000;
		rep(i, 0, K){
			out=max(out,solve(0,i));
		}
				
		printf("%d\n", out);	
	}
	 
return 0;
}
