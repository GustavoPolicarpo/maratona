// Author: Gustavo Policarpo
// Name: Cheap Trips
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2905

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<ll,int> ii;


double pd[10010][122][8];
bool mark[10010][122][8];
int N, D[10010], C[10010];

double solve(int i, int t, int q){
	if(i==N) return 0;
	if(mark[i][t][q]) return pd[i][t][q];
	mark[i][t][q] = true;
	
	double ret = 1e32, ter = 1e32;
	
	if(q==1) ret = solve(i+1, 0, 0)+(0.5*C[i]);
	else if(q>=2 && q<=5) ret = solve(i+1, 0, 0)+(0.25*C[i]);
	else ret = solve(i+1, 0, 0)+(1.0*C[i]);
	
	if(t+D[i]<120 && q<=5){
		if(q==1) ter = solve(i+1, t+D[i], q+1)+(0.5*C[i]);
		else if(q>=2 && q<=5) ter = solve(i+1, t+D[i], q+1)+(0.25*C[i]);
		else ter = solve(i+1, t+D[i], q+1)+(1.0*C[i]);
	}
	
	return pd[i][t][q] = min(ret, ter);
}

int main(){
	
	
	scanf("%d", &N);
	rep(i, 0, N) scanf("%d %d", &D[i], &C[i]);
	printf("%.2lf\n", solve(0, 0, 0));
	
	return 0;
}

