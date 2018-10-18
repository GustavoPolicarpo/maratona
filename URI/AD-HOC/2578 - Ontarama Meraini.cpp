// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ontarama Meraini
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2578

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

string m, t;

int main(){
	
	//freopen("in.txt", "r", stdin);
	
	// idimmlil
	// lim
	
	cin >> m >> t; 
	
	vector <int> vm(26, 0), vt(26, 0);
	rep(i, 0, t.size()) vt[t[i]-'a']++;
	
	int i=0, j=0, cnt=0, last=-1; ll ans=0;
	rep(j, 0, m.size()){
		
		int c=m[j]-'a';
		
		if(!vt[c]){
			rep(k, 0, 26) vm[k]=0;
			i=j+1;
			cnt=0;
			continue;
		}
		
		while(vm[c] == vt[c]) vm[m[i++]-'a']--, cnt--;
		vm[c]++, cnt++;
		
		if(cnt==t.size()){
			ans+=(ll(i-last)*ll(m.size()-j));
			last=i;
		}
		
	}
	
	printf("%lld\n", ans);
		
	return 0;
	
}
