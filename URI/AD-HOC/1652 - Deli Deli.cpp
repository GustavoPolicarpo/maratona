// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Deli Deli
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1652

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
	int L, N; cin >> L >> N;
	map<string, string> cor;
	set <char> vog;
	vog.insert('a'), 
	vog.insert('e'), 
	vog.insert('i'), 
	vog.insert('o'), 
	vog.insert('u');
	string a, b;
	rep(i, 0, L){
		cin >> a >> b;
		cor[a]=b;
	}
	rep(i, 0, N){
		cin >> a;
		if(cor.count(a)){
			cout << cor[a] << endl;
			continue;
		}
		int tam=a.size();
		if(tam>1){
			if(a[tam-1]=='y' && !vog.count(a[tam-2])){
				rep(i, 0, tam-1) cout << a[i];
				cout << "ies\n";
				continue;
			}
			if(a[tam-1]=='h' && a[tam-2]=='c'){
				cout << a << "es\n";
				continue;
			}
			if(a[tam-1]=='h' && a[tam-2]=='s'){
				cout << a << "es\n";
				continue;
			}			 
		}
		if(a[tam-1]=='o' || a[tam-1]=='s' || a[tam-1]=='x'){
			cout << a << "es\n";
			continue;
		}
		cout << a << "s\n";
	}

return 0;
}


