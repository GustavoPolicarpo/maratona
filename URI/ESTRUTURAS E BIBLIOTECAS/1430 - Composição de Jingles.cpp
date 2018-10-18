// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Composição de Jingles
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1430

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;


int main()
{
	map <char, double> nota;
	nota['W']=1.0, nota['H']=1.0/2.0, nota['Q']=1.0/4.0, nota['E']=1.0/8.0,    
	nota['S']=1.0/16.0, nota['T']=1.0/32.0, nota['X']=1.0/64.0;
	
	string in;
	while(cin >> in && in!="*"){
		int certo=0;
		double count =0;
		rep(i, 1, in.size()){
			//cout << fixed << setprecision(4) << in[i] << " " << nota['E']<< endl;
			if(in[i]=='/'){
				if(count>1-error && count<1+error){
					certo++;
				}
				count=0;		
			}
			else
				count+=nota[in[i]];
		}
		cout << certo << endl;
	}
	
return 0;
}
