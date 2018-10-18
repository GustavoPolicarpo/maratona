// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Joulupukki
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2025

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair < int, int > ii;
typedef pair < ii, int > iii;

const int INF = 0x3f3f3f3f;




int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N; cin >> N; cin.ignore();
	
	while(N--){
		string s; getline(cin, s);
		
		string aux;
		rep(i, 0, s.size()){
			if(s[i]==' '){
				if(aux.size()==11 && aux[aux.size()-1]=='.'){
					aux="Joulupukki.";
				}
				else if(aux.size()<=10 && aux.find("oulupukk")!=-1){
					aux="Joulupukki";
				}
				cout << aux; aux.clear();
				cout << ' ';
			}
			else{
				aux.pb(s[i]);
			}
		}
		if(aux.size()==11 && aux[aux.size()-1]=='.'){
			aux="Joulupukki.";
		}
		else if(aux.size()<=10 && aux.find("oulupukk")!=-1){
			aux="Joulupukki";
		}
		cout << aux; aux.clear();
		cout << '\n';
	}
	
	
	return 0;
	
}
