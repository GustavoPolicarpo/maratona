// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pudim
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2824

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
int ta, tb;

int dp[5005][5005];
int sol(){
	for(int i=ta-1; i>=0; i--){
		for(int j=tb-1; j>=0; j--){
			if(A[i]==B[j]) dp[i][j] = dp[i+1][j+1] + 1;
			else dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
		}
	}
	return dp[0][0];
}

int main(){
	
	gets(A); ta = strlen(A);
	gets(B); tb = strlen(B);
	printf("%d\n", sol());
	
	return 0;
} 
