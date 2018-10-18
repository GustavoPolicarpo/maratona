// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Olimpíadas de Natal
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2018

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

struct quadro{
	int gold, prata, bronze;
	string nome;
};

bool comp(quadro a, quadro b)
{
	if(a.gold > b.gold) return true;
	if(a.gold < b.gold) return false;
	
	if(a.prata > b.prata) return true;
	if(a.prata < b.prata) return false;
	
	if(a.bronze > b.bronze) return true;
	if(a.bronze < b.bronze) return false;
	
	if(a.nome<b.nome) return true;
	return false;
	
}
int main()
{
	string modalidade, um, dois, tres;
	map <string, quadro> tab; tab.clear();
	map <string, quadro>::iterator it;
	while(getline(cin, modalidade)){
		if(modalidade=="arroz") break;
		getline(cin, um), getline(cin, dois), getline(cin, tres);
		tab[um].gold++, tab[dois].prata++, tab[tres].bronze++;
	}
	cout << "Quadro de Medalhas" << endl;
	vector<quadro> out; quadro aux;
	for(it=tab.begin(); it!=tab.end(); it++){
		aux.nome=it->first;
		aux.gold=it->second.gold;
		aux.prata=it->second.prata;
		aux.bronze=it->second.bronze;
		out.pb(aux);
	}
	sort(out.begin(), out.end(), comp);
	rep(i, 0, out.size()){
		cout << out[i].nome << " " << out[i].gold << " " << out[i].prata << " " << out[i].bronze << endl;
	}
	
return 0;	
}
