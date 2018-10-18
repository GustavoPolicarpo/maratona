// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Presentes de Natal
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2022

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
typedef pair < int, string > ii;
typedef pair < double, int > iii;

struct pres{
	string nome;
	double preco; int pref;
};

bool cmp(pres a, pres b)
{
	if(a.pref>b.pref) return true;
	if(a.pref<b.pref) return false;
	
	if(a.preco>b.preco) return false;
	if(a.preco<b.preco) return true;
	
	if(a.nome>b.nome) return false;
	return true;
}
int main()
{
	string lista; int N;
	while(cin >> lista >> N){
		vector <pres> in;
		pres aux;
		rep(i, 0, N){
			cin.ignore();
			getline(cin, aux.nome);
			cin >> aux.preco >> aux.pref;
		//	cout << i << endl;
			in.pb(aux);
		}
		sort(in.begin(), in.end(), cmp);
		cout << "Lista de " << lista << endl;
		rep(i, 0, in.size()){
			cout << in[i].nome << " - R$" << fixed << setprecision(2) << in[i].preco << endl;
		}
		cout << endl;
	}
		
	
}
