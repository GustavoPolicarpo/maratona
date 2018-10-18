// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Balanço de Parênteses I
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1068

#include <bits/stdc++.h>

using namespace std;

int main(){
	string in; 
	
	while(getline(cin, in)){
		stack <char> s; bool correct=true;
		
		for(int i=0; i<in.size(); i++){
			if(in[i]=='(') s.push(in[i]);
			else if(in[i]==')'){
				if(s.empty()){
					correct=false;
					break;
				}
				s.pop();
			}
		}
		if(!correct || !s.empty()) puts("incorrect");
		else puts("correct");
	}
	
	return 0;
}
