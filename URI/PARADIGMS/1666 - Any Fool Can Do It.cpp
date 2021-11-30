// Author: Gustavo Policarpo
// Name: Any Fool Can Do It
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1666

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
typedef pair<ii, int> iii;

#define INF 0x3f3f3f3f

string s;
int pd[202][202];
int conjunto(int i, int j);

int atomo(int i, int j){
	if(pd[i][j]!=-1) return pd[i][j];
	if(s[i]=='{' || s[i]=='}' || s[i]==',') return pd[i][j]=1;
	return pd[i][j]=0;
}
int elemento(int i, int j){
	if(pd[i][j]!=-1) return pd[i][j];
	if(i==j) return pd[i][j]=atomo(i, j);
	return pd[i][j]=conjunto(i, j);
}
int lista(int i, int j){
	if(pd[i][j]!=-1) return pd[i][j];
	int ret=elemento(i, j);
	rep(k, i+1, j) if(s[k]==',') ret=max(ret, elemento(i, k-1)&lista(k+1, j));
	return pd[i][j]=ret;
}
int elementodalista(int i, int j){
	if(pd[i][j]!=-1) return pd[i][j];
	if(i>j) return pd[i][j]=1;
	return pd[i][j]=lista(i, j);
}

int conjunto(int i, int j){
	if(pd[i][j]!=-1) return pd[i][j];
	if(s[i]=='{' && s[j]=='}') return pd[i][j]=elementodalista(i+1, j-1);
	return pd[i][j]=0;
}

int main(){
	
	int T; cin >> T;
	
	rep(z, 0, T){
		cin >> s; memset(pd, -1, sizeof pd);
		conjunto(0, s.size()-1) ? printf("Word #%d: Set\n", z+1) : printf("Word #%d: No Set\n", z+1);
	}
	
	return 0;
}
