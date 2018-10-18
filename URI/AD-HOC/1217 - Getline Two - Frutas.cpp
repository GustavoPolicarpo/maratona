// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Getline Two - Frutas
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1217

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;
int N;
long int  KGD[1000000];
long double G, KG, GT;
int cont=1, i;
string F;



int main()
{
	cin >> N;
	int N2=N;
	while(N--)
	{
		cin >> G;
		cin.ignore();
		getline(cin, F);
		GT=GT+G;
			stringstream ff;
			ff << F;
			while(ff >> F) 
			{
				KG++;
				KGD[cont]++;
			}
		cont++;
		
	}
	cont=0;
	while(N2--)
	{	
		cont++;
		cout << "day " << cont << ": " << KGD[cont] << " kg" << endl;	
	}
	cout << fixed << setprecision(2) << KG/cont << " kg by day" << endl <<
	"R$ " << GT/cont << " by day" << endl;
 

return 0;	
}




