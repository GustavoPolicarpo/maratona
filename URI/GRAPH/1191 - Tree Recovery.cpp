// Author: Gustavo Policarpo
// Name: Tree Recovery
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1191

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

#define INF 0x3f3f3f3f
const int mod=1e9+7;


int at; string pre, inf;

void rec(int i, int j){
	
	if(i<=j){
		
		int p=inf.find(pre[at++]);
		rec(i, p-1);
		rec(p+1, j);
		cout << inf[p];
		
	}
}

int main(){
	
	
	while(cin >> pre >> inf){
		at=0;
		rec(0, pre.size()-1);
		cout << '\n';
	}
		
	return 0;
	
}
