// Author: Gustavo Policarpo
// Name: Houseplant
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2796

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

int N, M, K;
char mat[1010][1010];
int altura[1010][1010];
vector <ii> rect, good;

void add(int x, int y){
	if(x>y) swap(x, y);
	if(x==0) return;
	rect.pb(ii(x, y));
}

bool check(int C, int L){
	int p = lower_bound(good.begin(), good.end(), ii(C, 0))-good.begin();
	return (p<good.size() && good[p].S>=L);
}

int main(){
	
	scanf("%d %d", &N, &M);
	rep(i, 0, N) scanf("%s", mat[i]);
	
	rep(i, 0, N){
		rep(j, 0, M){
			if(mat[i][j]=='#'){
				altura[i][j] = 0;
			}else{
				altura[i][j] = 1;
				if(i) altura[i][j] += altura[i-1][j];
			}
		}
	}
	
	/*
	4 5
	#####
	#...#
	....#
	#####
	5
	1 2
	2 3
	2 2
	3 3
	1 3
	
	*/
	
	rep(i, 0, N){
		stack <ii> st;
		rep(j, 0, M){
			if(!st.size() || st.top().S<=altura[i][j]) st.push(ii(j, altura[i][j]));
		 	else{
		 		ii tp = st.top(); st.pop();
		 		add(tp.S, st.empty()?j:j-st.top().F-1);
		 		j--;
			}
		}
		while(!st.empty()){
			ii tp = st.top(); st.pop();
		 	add(tp.S, st.empty()?M:M-st.top().F-1);
		}
	}
	
	sort(rect.begin(), rect.end());
	for(int i=0; i<rect.size(); i++){
		while(good.size() && good[good.size()-1].S<=rect[i].S) good.pop_back();
		good.pb(rect[i]);
	}
	
	//rep(i, 0, good.size()) cout << good[i].F << " " << good[i].S << '\n'; cout << '\n';
	
	scanf("%d", &K);
	int C, L, area = 0, comp = 0, larg = 0;
	rep(i, 0, K){
		scanf("%d %d", &C, &L);
		if(L*C < area) continue;
		
		if(check(L, C) || check(C, L)){
			if(area < C*L) area = C*L, comp = C, larg = L;
			else if(L>larg) comp = C, larg = L;
		}
	}
	
	cout << comp << " " << larg << '\n';
	
	return 0;
}
