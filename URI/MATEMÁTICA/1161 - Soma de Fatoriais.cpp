// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma de Fatoriais
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1161

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

long long int N1, N2, S1, S2;

int main()
{
	while(cin >> N1 , cin >> N2) 
	{
		S1=1; S2=1;
		
		for(N1; N1>=2; N1--) { S1=S1*N1*(N1-1); N1--; }
		
		for(N2; N2>=2; N2--) { S2=S2*N2*(N2-1); N2--; }
		
		cout << S1+S2 << endl;			
	}
 
return 0;
}


