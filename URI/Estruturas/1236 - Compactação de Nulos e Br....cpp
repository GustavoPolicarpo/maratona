// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Compactação de Nulos e Br...
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1236

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;




int main(){
	
	int T; cin >> T; cin.ignore();
	
	while(T--){
		
		string s; getline(cin, s);
		
		rep(i, 0, s.size()){
			if(s[i]!='0' && s[i]!=' ') cout << s[i];
			else{
				char op=s[i];
				int cnt=0;
				while(i<s.size() && s[i]==op){
					i++, cnt++;
					if(cnt==255) break;
				}
				if(cnt>2){
					if(op=='0') cout << '#';
					else cout << '$';
					cout << char(cnt);
				}else{
					rep(j, 0, cnt){
						cout << op;
					}
				}
				i--;
			}
		}
		
		cout << '\n';
		
	}
	
	return 0;
	
}
