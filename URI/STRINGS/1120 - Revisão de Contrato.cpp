// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Revisão de Contrato
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1120

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <string.h>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

char D;
string N;
stack <char> n, o;
char T;
string O, GO;
bool zero = false;



int main()
{
	while(1)
	{
		cin >> D >> N;
		if(D=='0' && N=="0") break;
		for(int i=0; i<N.size(); i++) n.push(N[i]);
		for(int i=0; i<N.size(); i++)
		{
			
			T=n.top();
			if(T!=D) O=O+T;
			
			n.pop();
		}
		for(int i=0; i<O.size(); i++) o.push(O[i]);
		for(int i=0; i<O.size(); i++)
		{
			if(o.top()!='0') zero=true;
			if(o.top()!='0' || zero==true) GO=GO+o.top();
			
			o.pop();
			
		}
		if(GO=="")GO="0";
		cout << GO << endl;
		
		
		O="";
		GO="";	
		zero=false;
	}

return 0;

}


