// Author: Gustavo Policarpo
// Name: Jumping Frog
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1961

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>
#include <cmath>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int P, N, i=1;


int main()
{
	cin >> P >> N;
	int C[N];
	cin >> C[0];
	
	while(N--)
	{
		cin >> C[i];
		
		if(abs(C[i]-C[i-1])>P)
		{
			cout << "GAME OVER"; break;
		}
		
		if(N==1) 
		{
			cout << "YOU WIN"; break;	
		}	
		i++;	
	}
	cout << endl;
	
	

 
}

