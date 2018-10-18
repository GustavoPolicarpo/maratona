// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: LED
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1168

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>

using namespace std;

int N;
string V;
stack <char> v;
char T;
long long int NL;




int main()
{
	cin >> N;
	while(N--)
	{
		cin >> V;
		for(int i=0; i<V.size(); i++) v.push(V[i]);
		for(int i=0; i<V.size(); i++)
		{
			T=v.top();
			switch(T)
			{
				case '1': NL=NL+2; break;
				case '2': NL=NL+5; break;
				case '3': NL=NL+5; break;
				case '4': NL=NL+4; break;
				case '5': NL=NL+5; break;
				case '6': NL=NL+6; break;
				case '7': NL=NL+3; break;
				case '8': NL=NL+7; break;
				case '9': NL=NL+6; break;
				case '0': NL=NL+6; break;
			}
			v.pop();
		}
		cout << NL << " leds" << endl;
		string V="";
		NL=0;	
	}

	
return 0;

}
