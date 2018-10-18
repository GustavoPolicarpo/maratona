// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Máquina de Verificação Au...
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1743

#include<bits/stdc++.h>

using namespace std;


int A[5];
int B[5];
int C[5];


int main()
{
	for(int i=0; i<5; i++) cin >> A[i];
	for(int i=0; i<5; i++) cin >> B[i];
	for(int i=0; i<5; i++) C[i]=A[i]+B[i];
	for(int i=0; i<5; i++)
	{
		if(C[i]!=1) 
		{
			cout << "N" << endl;
			break;
		}
		if(i==4) cout << "Y" << endl;
	}
		
return(0);
}

