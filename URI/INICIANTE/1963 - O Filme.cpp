// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Filme
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1963

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>
#include <cmath>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

double A, B, S;


int main()
{
	cin >> A >> B;
	
	S=B-A;
	S=S/A*100;
	
	cout << fixed << setprecision(2) << S << "%" << endl;
	
 
}

