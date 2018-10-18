// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Papagaio Poliglota
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2850

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 
int main(){
    
	string a;
	while(getline(cin, a)){
		if(a=="esquerda") puts("ingles");
		else if(a=="direita") puts("frances");
		else if(a=="nenhuma") puts("portugues");
		else puts("caiu");
	}
    
    return 0;
}  
