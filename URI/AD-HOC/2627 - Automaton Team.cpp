// Author: Gustavo Policarpo
// Name: Automaton Team
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2627

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

char s[100010];
int dp[100010][26];

int main(){
	
	int N, K;
	
	while(scanf("%d %d", &N, &K)!=EOF){ scanf("%s", s);
		
		rep(i, 0, N) rep(j, 0, 26) dp[i][j] = 0;
		bool yep = false;
		
		dp[N-1][s[N-1]-'a'] = 26-(s[N-1]-'a');
		for(int i=N-2; i>=0; i--){
			char c = s[i]-'a';
			dp[i][25] = dp[i+1][25];
			for(int j=24; j>=0; j--) dp[i][j] = max(dp[i][j+1], dp[i+1][j]);
			dp[i][s[i]-'a'] += 26-(s[i]-'a');
		}
		
		int ans = 0; 
		rep(i, 0, 26) ans = max(ans, dp[0][i]);
		if(ans>=K) puts("Aceita");
		else puts("Rejeita");
	}
	
	
	return 0;
}
