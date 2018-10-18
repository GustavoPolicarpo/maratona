// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Camisetas
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1258

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

struct cam{
	string nome, tam, cor;
};

bool comp(cam a, cam b)
{
	if(a.cor>b.cor) return false;
	if(a.cor<b.cor) return true;
	
	if(a.tam>b.tam) return true;
	if(a.tam<b.tam) return false;
	
	if(a.nome>b.nome) return false;
	return true;
	
}

int main()
{
	int N; bool mark=false;
	while(cin >> N && N){
		if(mark) cout << endl;
		else mark=true;
		cam in[N]; 
		rep(i, 0, N){
			cin.ignore();
			getline(cin, in[i].nome);
			cin >> in[i].cor >> in[i].tam;
		}
		sort(in, in+N, comp);
		rep(i, 0, N)
			cout << in[i].cor << " "
				 << in[i].tam << " "
				 << in[i].nome << "\n";	
	}
	
return 0;
}
