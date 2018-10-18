// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Vogais Alienígenas
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2150

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	string in, frase; 
	while(cin >> in){
		set <char> let;
		cin.ignore();
		rep(i, 0, in.size()){
			if(!isspace(in[i])) let.insert(in[i]);
		}
		frase="";
		getline(cin, frase);
		int cont=0;
		rep(i, 0, frase.size())
			if(let.count(frase[i])) cont++;
		
		cout << cont << endl;
		
	}

return 0;
}


