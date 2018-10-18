// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dabriel e Suas Strings
// Nível: 2
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2842

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

string A, B;
int pd[1010][1010];

int solve(int i, int j){
	if(i==A.size() && j==B.size()) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	int ret = 0x3f3f3f3f;
	if(i<A.size() && j<B.size() && A[i]==B[j]) ret = min(ret, solve(i+1, j+1)+1);
	if(i<A.size()) ret = min(ret, solve(i+1, j)+1);
	if(j<B.size()) ret = min(ret, solve(i, j+1)+1);
	return pd[i][j] = ret;
}

int main(){
	
	cin >> A >> B; memset(pd, -1, sizeof pd);
	printf("%d\n", solve(0, 0));

	return 0;
}
