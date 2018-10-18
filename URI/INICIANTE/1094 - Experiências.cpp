// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Experiências
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1094

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double N, Q, R, S, C, TT;
string T;

int main()
{
	cin >> N;
	
	for(int con=1; con<=N; con++)
	{
		
		cin >> Q >> T;
		
		if(T=="R") { R=R+Q; TT=TT+Q;
		}
		else if(T=="S") { S=S+Q; TT=TT+Q;
		}
		else if(T=="C") { C=C+Q; TT=TT+Q;
		}
	}
	
	cout << "Total: " << TT << " cobaias" << endl;
	cout << "Total de coelhos: " << C << endl;
	cout << "Total de ratos: " << R << endl;
	cout << "Total de sapos: " << S << endl;
	
	cout << fixed << setprecision(2);
	cout << "Percentual de coelhos: " << C/TT*100 << " %" << endl;
	cout << "Percentual de ratos: " << R/TT*100 << " %" << endl;
	cout << "Percentual de sapos: " << S/TT*100 << " %" << endl;
		
return 0;	
}
