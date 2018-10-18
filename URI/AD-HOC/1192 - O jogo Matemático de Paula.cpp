// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O jogo Matemático de Paula
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1192

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N;
int A, B;
char C;



int main()
{
	cin >> N;
	while(N--)
	{
		cin >> A >> C >> B;
		if(A==B) cout << A*B << endl;
		else if(isupper(C)) cout << B-A << endl;
		else if(islower(C)) cout << A+B << endl;	
	}
	
return(0);	
}
	



