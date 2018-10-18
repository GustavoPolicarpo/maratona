// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Elfo das Trevas
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1766

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



struct renas
{
    char nome[101];
    int peso, idade;
    double altura;
};
 

 
bool comp(renas a, renas b)
{
	if(a.peso > b.peso) return true;
    if(a.peso < b.peso) return false;
    
    if(a.idade < b.idade) return true;
    if(a.idade > b.idade) return false;
    
    if(a.altura < b.altura) return true;
    if(a.altura > b.altura) return false;
    
    if(strcmp(a.nome, b.nome) < 0) return true;
    return false;
}
 
 
int main()
{
	 int n;
	 cin >> n;
	 for(int g=1; g<=n; g++)
	 {
	    int N, M;
	    cin >> N >> M;
	    
	   	renas p[N];
	    for(int i=0; i<N; i++)
	        cin >> p[i].nome >> p[i].peso >> p[i].idade >> p[i].altura;
	       
	    sort(p, p+N, comp);
	   
	   	cout << "CENARIO {" << g << '}' << endl;
	    for(int i=0; i<M; i++)
	        cout << i+1 << " - " << p[i].nome << "\n";
	}
return 0;
}







