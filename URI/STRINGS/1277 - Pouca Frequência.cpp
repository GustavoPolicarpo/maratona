// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pouca Frequência
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1277

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)

int main()
{
	int T; cin >> T;
	while(T--){
		int N; cin >> N;
		string pre;
		
		vector <string> al;
		al.clear();
		
		rep(i, 0, N){
			cin >> pre;
			al.push_back(pre);
		}
		vector <string> bur;
		bur.clear();
		
		rep(i, 0, N){
			double t, p=0;
			cin >> pre;
			t=pre.size();
			rep(j, 0, pre.size()){
				if(pre[j]=='P') p++;
				else if(pre[j]=='M')t--;
			}
			if(p/t<0.75) bur.push_back(al[i]);
		}
		bool mark=false;
		rep(i, 0, bur.size()){
			if(mark) cout << " ";
			else mark=true;
			cout << bur[i];
		}
		cout << endl;
	}
	
return 0;	
}
