// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência Lógica
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1144

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, SEQ1=1, SEQ2=1, SEQ3=1;

int main()
{
	cin >> N;
	for(int con=1; con<=N; con++)
	{
		cout << SEQ1 << " " <<  SEQ2 << " " << SEQ3 << endl;
		SEQ2++;
		SEQ3++;
		cout << SEQ1 << " " <<  SEQ2 << " " << SEQ3 << endl;
		SEQ1++;
		SEQ2=SEQ2+2*con;
		SEQ3=SEQ3+3*(con+con*con);
	}
	
	
return 0;	
}
