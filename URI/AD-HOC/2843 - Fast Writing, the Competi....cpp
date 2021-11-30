// Author: Gustavo Policarpo
// Name: Fast Writing, the Competi...
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2843

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

int check(int Am, int Rm, int Em, int Av, int Rv, int Ev, int S){
	int Ta = (ll)Am*2 + (ll)Rm + (ll)Em*S;	
	int Tb = (ll)Av*2 + (ll)Rv + (ll)Ev*S;
	if(Ta<Tb) return -1;
	if(Ta==Tb) return 0;
	if(Ta>Tb) return 1;
}

int ans[65536], N, fase;
ll textSize;
vector <iii> players;
string S;

void solve(){
	vector <iii> pass;
	for(int i=0; i<players.size(); i+=2){
		int result = check(0, players[i].S.F, players[i].S.S, 0, players[i+1].S.F, players[i+1].S.S, textSize);
		if(result==-1 || result==0){
			pass.pb(players[i]);
			ans[players[i+1].F] = fase;
		}else{
			pass.pb(players[i+1]);
			ans[players[i].F] = fase;
		}
	}
	swap(players, pass);
}

int main(){
	
	cin >> N;
	
	ii aux;
	rep(i, 0, N){
		cin >> aux.F >> aux.S;
		players.pb(iii(i, aux));
	}
	
	getline(cin, S); getline(cin, S);
	
	textSize = S.size(), fase = 1;
	while(players.size()>1){
		solve();
		textSize = textSize + textSize;
		fase++;
	}	ans[players[0].F] = fase;
	
	
	rep(i, 0, N){
		if(i) cout << " ";
		cout << ans[i];
	}	cout << '\n';


	return 0;
}
