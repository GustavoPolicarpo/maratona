// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cara ou Coroa
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1329

#include <iostream>
#include <iomanip>

using namespace std;


int N=1, R;
int M, J;


int main()
{
	while(1)
	{
		M=0; J=0;
		cin >> N;
		if(N==0) break;
		while(N--)
		{
			cin >> R;
			if(R==0) M++;
			else if(R==1) J++;		
		}
		cout << "Mary won " << M << " times and John won " << J << " times" << endl;
				
	}

return 0;	
}
