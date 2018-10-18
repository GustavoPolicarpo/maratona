// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ordenação por Tamanho
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1244

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



bool comp(string a, string b)
{
	return a.size()>b.size() ;

}

int main()
{
	int N;
	cin >> N; cin.ignore();
	while(N--){
		string all, aux;
		getline(cin, all);
		vector <string> pal;
		rep(i, 0, all.size()){
			if(all[i]==' '){
				pal.pb(aux);
				aux="";
			}
			else
				aux+=all[i];
		}
		pal.pb(aux);
		
		stable_sort(pal.begin(), pal.end(), comp);
		rep(i, 0, pal.size()-1)
			cout << pal[i] <<  " " ;
		cout << pal[pal.size()-1];
		cout << endl;
		
		
	}
	
return 0;
}
