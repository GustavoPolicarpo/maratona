// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mjölnir
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1865

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int C, N;
string NM;


int main()
{
	cin >> C;
	while(C--)
	{
		cin >> NM >> N;
		if(NM=="Thor") cout << "Y" << endl;
		else cout << "N" << endl;
		N=0; NM="";		
	}
		
	return 0;
}
