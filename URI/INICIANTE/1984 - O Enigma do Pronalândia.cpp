// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Enigma do Pronalândia
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1984

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>
#include <cmath>
#include <stack>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

string N;

int main()
{
	cin >> N;
	stack <char> n;
	for(int i=0; i<N.size(); i++ ) n.push(N[i]);
	for(int i=0; i<N.size(); i++ ) 
	{
		cout << n.top();
		n.pop();
	}
	cout << endl;
	
	
	
return(0); 
}

