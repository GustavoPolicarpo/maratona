// Author: Gustavo Policarpo
// Name: Average 3
// Level: 5
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1040

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double N1, N2, N3, N4, E;
double NP, NF;

int main()
{	
	cout << fixed << setprecision(1);
	
	cin >> N1 >> N2 >> N3 >> N4;
	
	NP=(N1*2 + N2*3 + N3*4 + N4*1)/10;
		
	cout << "Media: " << NP << endl;
	
	if(NP>=7.0)
	{
		cout << "Aluno aprovado." << endl;
	}
	else if(NP>= 5.0 && NP<7)
	{
		cout << "Aluno em exame." << endl;
		cin >> E;
		cout << "Nota do exame: " << E << endl;
		
		NF = (NP+E)/2;
		if (NF>=5.0)
		{
			cout << "Aluno aprovado." << endl;
			cout << "Media final: " << NF << endl;
		}
		else
		{
			cout << "Aluno reprovado." << endl;
			cout << "Media final: " << NF << endl;
		}			
	}
	else
	{
		cout << "Aluno reprovado." << endl;
	}
				
	return(0);
}
