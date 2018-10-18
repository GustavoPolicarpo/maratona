// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Zerinho ou Um
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1467

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int A, B, C;

int main () 
{
	while(cin >> A >> B >> C)
	{
		if(A==B && A==C) cout << "*" << endl;
		else if(A==B && A!=C) cout << "C" << endl;
		else if(A==C && A!=B) cout << "B" << endl;
		else if(B==C && B!=A) cout << "A" << endl;
	}
  
}
