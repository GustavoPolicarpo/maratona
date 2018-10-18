// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Feira de Adoção
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2535

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

int main(){

	int n;
	
	while(cin >> n){
		cin.ignore();
		string esp, ra, no, s; int ans=0;
		
		rep(i, 0, n){
			getline(cin, esp);
			getline(cin, ra);
			getline(cin, no);
			getline(cin, s);
			
			if(esp!="cachorro") continue;
			if(no.find(' ')==-1) continue;
			
			stringstream ss; s.clear();
			ss << no;
			
			while(ss >> s){
				if(s[0]==ra[0]){
					ans++;
					break;
				}
			}
		}
		
		cout << ans << '\n';
		
	
	}

	return 0;

}

