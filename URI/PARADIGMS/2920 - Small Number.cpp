// Author: Gustavo Policarpo
// Name: Small Number
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2920

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


string N;
int K, yep, F;
int pd[101][101];
vector <int> pos[10];
string ans;

int solve(int i, int t){
	if(yep) return 1;
	if(t==F+1) return yep = 1;
	if(i==N.size()) return 2;
	if(pd[i][t]!=-1) return pd[i][t];
	int ret = 2;
	rep(j, 0, 10){
		int p = upper_bound(pos[j].begin(), pos[j].end(), i) - pos[j].begin();
		ret = solve(pos[j][p], t+1);
		if(ret == 1){
			ans.pb(N[i]);
			return pd[i][t] = 1;
		}
		if(yep) return 1;
	}
	return pd[i][t] = ret;
}

int main(){
	
	while(cin >> N >> K){
		memset(pd, -1, sizeof pd); yep = 0;
		rep(i, 0, 10) pos[i].clear(); ans.clear();
		
		rep(i, 0, N.size()) pos[N[i]-'0'].pb(i);
		rep(i, 0, 10) pos[i].pb((int)N.size());
		F = (int)N.size()-K;
		
		yep = 0;
		rep(i, 0, 10){
			solve(pos[i][0], 1);
			if(yep) break;
		}
		
		reverse(ans.begin(), ans.end());
		cout << ans << '\n';
	}	
	

	return 0;
} 
