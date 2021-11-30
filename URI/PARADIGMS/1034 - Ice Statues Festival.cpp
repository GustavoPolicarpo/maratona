// Author: Gustavo Policarpo
// Name: Ice Statues Festival
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1034

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

typedef pair < int, int > ii;
typedef long long int ll;

int dp[1000001];
int solve(int N, int M, int * m) 
{
    dp[0] = 0;
    rep(i, 1, M+1){
        dp[i] = 1000001;
       rep(j, 0, N){
            if(i-m[j] >= 0) {
                dp[i] = min(dp[i], dp[i-m[j]]+1);
            }
        }
    }
    return dp[M];
}

int main()
{
	int T; cin >> T;
	while(T--){
		int N, M; cin >> N >> M; int m[N];
			
		rep(i, 0, N)
			cin >> m[i];
	
	int out=solve(N, M, m);		
	cout << out << endl;
	}
	
return 0;	
}
