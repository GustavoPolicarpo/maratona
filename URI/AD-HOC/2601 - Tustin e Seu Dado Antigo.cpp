// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tustin e Seu Dado Antigo
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2601

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

char dado[6]; map<int, int> C;

int check(){
	if(dado[0]+dado[5]!=103) return 0;
	if(dado[1]+dado[3]!=103) return 0;
	if(dado[2]+dado[4]!=103) return 0;
	return 1;
}

int solve(int p){
	
	if(p==6) return check();
	if(dado[p]!='*') return solve(p+1);
	int ret=0;
	rep(i, 1+'0', 7+'0'){
		if(C[i]) continue;
		C[i]++, dado[p]=i;
		ret+=solve(p+1);
		C[i]--, dado[p]='*';
	}
	return ret;
}

int main(){
	
	int T; cin >> T;
	
	while(T--){
		C.clear();
		rep(i, 0, 6) cin >> dado[i], C[dado[i]]++;
		cout << solve(0) << '\n';
	}
	
	return 0;
}
