// Author: Gustavo Policarpo
// Name: Pudim
// Level: 9
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2824

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

char A[5005], B[5005];
int ta, tb, pd[5005][5005];

int solve(int i, int j){
	if(i==ta || j==tb) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	int ret = 0;
	if(A[i]==B[j]) ret = solve(i+1, j+1)+1;
	else ret = max(solve(i+1, j), solve(i, j+1));
	return pd[i][j] = ret;
}

int main(){
	
	memset(pd, -1, sizeof pd);
	gets(A); ta = strlen(A);
	gets(B); tb = strlen(B);
	printf("%d\n", solve(0, 0));
	
	return 0;
} 
