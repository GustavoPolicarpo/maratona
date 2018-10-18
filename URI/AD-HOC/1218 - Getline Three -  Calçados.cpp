// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Getline Three -  Calçados
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1218

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N;
string NN;
string ALL;


int cont=0;
int F, M;
int mark = 0;



int main()
{
	while(cin >> N)
	{
		
     		 
		F=0; M=0;
		cont++;
		ostringstream convert; 
		convert << N;
		NN = convert.str();
		cin.ignore();
		getline(cin, ALL);
		
			stringstream all;
			all << ALL;
			while(all >> ALL)
			{
				if(ALL==NN)
				{
					all >> ALL;
					if(ALL=="F") F++;
					else if(ALL=="M") M++;
				}
			}
			
		if(mark!=0)
            cout<<endl;
        else
            mark = 1;
			
			
		cout << "Caso " << cont << ":" << endl;
		cout << "Pares Iguais: " << F+M << endl;
		cout << "F: " << F << endl;
		cout << "M: " << M << endl;
		
	}
	
	
	
	
	
return(0);	
}
	



