// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Aumento de Salário
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1048

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double IN, R, S;
int P;

int main()
{	
	cin >> IN;
	
	cout << fixed << setprecision(2);
	
	if(IN<=400) { R = IN*15/100; S = IN+R; P=15;
	}
	else if (IN<=800) { R=IN*12/100; S = IN+R; P=12;
	}
	else if (IN<=1200) { R=IN*10/100; S = IN+R; P=10;
	}
	else if (IN<=2000) { R=IN*7/100; S = IN+R; P=7;
	}
	else { R=IN*4/100; S = IN+R; P=4;
	}
	
	cout << "Novo salario: " << S << endl;
	cout << "Reajuste ganho: " << R << endl;
	cout << "Em percentual: " << P << " %" <<endl;
		
	return(0);
	
}
