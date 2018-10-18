// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Média 2
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1006

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A, B, C, MEDIA;

int main()
{	
	cin >> A >> B >> C;
	
	MEDIA=((A*2)+(B*3)+(C*5))/10;
	
	cout << fixed << setprecision(1);
	cout<<"MEDIA = "<< MEDIA << endl;
	
	return(0);
}
