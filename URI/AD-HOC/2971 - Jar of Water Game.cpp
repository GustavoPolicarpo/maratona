// Author: Gustavo Policarpo
// Name: Jar of Water Game
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2971

#include <bits/stdc++.h>

// boca-submit-run teammgmu19 GGZBKdXEx PP C++14 FF

#define rep(i, a, b) for(int i = a; i < b; i++)
#define REP(i, a, b) rep(i, a, b+1)
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) cout << #a << " = "  << a << " ---- " << #b << " = " << b << endl;
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, K;
string card[20];
int jog[20];

string deck = "A23456789DQJK";

bool cmp(char a, char b){
	int ia, ib;
	rep(i, 0, deck.size()){
		if(deck[i]==a) ia = i;
		if(deck[i]==b) ib = i;
	}
	return ia < ib;
}

int check(){
	rep(i, 0, N){
		sort(card[i].begin(), card[i].end(), cmp);
		if(jog[i]) continue;
		char c = card[i][0];
		int yep = 1;
		
		rep(j, 0, card[i].size()){
			if(card[i][j]!=c){
				yep = 0;
				break;
			}
		}
		if(yep) return i;
	}
	return -1;
}

char getCard(int p){
	map<char, int> f;
	rep(i, 0, card[p].size()) f[card[p][i]]++;
	int id, mx = 10;
	rep(i, 0, card[p].size()){
		char c = card[p][i];
		if(f[c] < mx){
			id = i;
			mx = f[c];
		}
	}
	char ret = card[p][id];
	card[p].erase(card[p].begin() + id);
	return ret;
}



int main(){

	cin >> N >> K; K--;
	string s; jog[K] = 1;
	
	rep(i, 0, N) cin >> card[i];
	
	int p = K;
	while(42){
		
		int id = check();
		
		if(id!=-1){
			cout << id+1 << '\n';
			return 0;
		}
		
		int nx = (p+1)%N;
		if(jog[p]){
			if(jog[p]==2){
				jog[p] = 0;
				jog[nx] = 1;
				p = nx;
				continue;
			}else{
				jog[p]++;
			}
		}
		
		char c = getCard(p);
		card[nx].pb(c);
		p = nx;
	
	}
	
	
}
