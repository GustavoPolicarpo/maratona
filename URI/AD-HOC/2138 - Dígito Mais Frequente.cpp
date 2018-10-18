// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dígito Mais Frequente
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2138

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


int main(){
	
	string s;
	while(cin >> s){
		int cnt[11], pos, m=-1;
		memset(cnt,0,sizeof cnt);
		rep(i, 0, s.size()) cnt[s[i]-'0']++;
		rep(i, 0, 10) if(m <= cnt[i]) m=cnt[i], pos=i;
		printf("%d\n", pos);
	}

	
	return 0;
}
