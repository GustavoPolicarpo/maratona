// Author: Gustavo Policarpo
// Name: Applying Tests
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2797

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int mat[1010][1010];
vector <int> tipo[1010][2];

int main(){
	
	int n, m, c;
	scanf("%d %d %d", &n, &m, &c);
	
	rep(i, 0, n){
		rep(j, 0, m){
			scanf("%d", &mat[i][j]);
			if(mat[i][j]==1) tipo[j][0].pb(i);
			if(mat[i][j]==2) tipo[j][1].pb(i);
		}
	}
	
	rep(j, 0, m-1){
		if(tipo[j][0].size()+tipo[j][1].size() && tipo[j+1][0].size()+tipo[j+1][1].size()){
			puts("N");
			return 0;
		}
	}
	
	rep(j, 0, m){
		rep(k, 0, 2){
			rep(i, 0, tipo[j][k].size()-1){
				if(tipo[j][k][i+1] - tipo[j][k][i] - 1 < c){
					puts("N");
					return 0;
				}
			}
		}
	}
	
	puts("S");
	
	
	return 0;
}
