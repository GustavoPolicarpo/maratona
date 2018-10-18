// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Papel, Tesoura, I Love You!
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2847

#include <bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define pb push_back

using namespace std;


int main()
{
	
	string t = {"Iloveyou!"};
	string s; getline(cin, s);
	
	int ft[255], fs[255];
	memset(ft, 0, sizeof ft);
	memset(fs, 0, sizeof fs);
	
	rep(i, 0, t.size()) ft[t[i]]++;
	rep(i, 0, s.size()) fs[s[i]]++;
	
	int ans = 0x3f3f3f3f;
	rep(i, 0, 255){
		if(ft[i]==0) continue;
		ans = min(ans, fs[i]/ft[i]);
	}
	
	cout << ans << '\n';
	

	return 0;
}

