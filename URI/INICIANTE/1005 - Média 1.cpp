// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Média 1
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1005

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A, B, MEDIA;

int main()
{	
	cin >> A >> B;
	
	MEDIA=((A*3.5)+(B*7.5))/11;
	
	cout << fixed << setprecision(5);
	cout<<"MEDIA = "<< MEDIA << endl;
	
	return(0);
}
