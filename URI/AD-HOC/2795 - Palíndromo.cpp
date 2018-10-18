// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Palíndromo
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2795

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

int N, K;
string S;
int dp[404], at[404];
int ct[404][404], cost[26][26];

int main(){
	
	rep(i, 0, 26) rep(j, 0, 26) cost[i][j] = min((i-j+26)%26, (j-i+26)%26);
	
	cin >> N >> K >> S;
	
	for(int i=N-1; i>=0; i--){
		for(int j=0; j<N; j++){
			if(i>=j) ct[i][j] = 0;
			else ct[i][j] = ct[i+1][j-1] + cost[S[i]-'a'][S[j]-'a'];
		}
	}
	
	rep(i, 0, N) dp[i] = ct[i][N-1], at[i] = 0x3f3f3f3f;
	
	for(int k=1; k<K; k++){
		for(int i=N-1; i>=0; i--){
			for(int j=i; j<N; j++){
				at[i] = min(at[i], dp[j+1]+ct[i][j]);
			}
		}
		swap(dp, at);
	}
	
	cout << dp[0] << '\n';
	
	return 0;
}
