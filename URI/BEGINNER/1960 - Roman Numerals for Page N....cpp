// Author: Gustavo Policarpo
// Name: Roman Numerals for Page N...
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1960

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N, aux, aux2, aux3;

int main()
{
	cin >> N;
	aux=N/100;

	switch(aux)
	{
		case 1: cout << 'C'; break;
		case 2: cout << "CC"; break;
		case 3: cout << "CCC"; break;
		case 4: cout << "CD"; break;
		case 5: cout << 'D'; break;
		case 6: cout << "DC"; break; 
		case 7: cout << "DCC"; break;
		case 8: cout << "DCCC"; break;
		case 9: cout << "CM"; break;
	}
	aux=N%100;
	aux=aux/10;
	
	switch(aux)
	{
		case 1: cout << 'X'; break;
		case 2: cout << "XX"; break;
		case 3: cout << "XXX"; break;
		case 4: cout << "XL"; break;
		case 5: cout << 'L'; break;
		case 6: cout << "LX"; break;
		case 7: cout << "LXX"; break;
		case 8: cout << "LXXX"; break;
		case 9: cout << "XC"; break;
	}
	aux=N%100%10;
	
	switch(aux)
	{
		case 1: cout << 'I'; break;
		case 2: cout << "II"; break;
		case 3: cout << "III"; break; 
		case 4: cout << "IV"; break;
		case 5: cout << 'V'; break;
		case 6: cout << "VI"; break;
		case 7: cout << "VII"; break;
		case 8: cout << "VIII"; break;
		case 9: cout << "IX"; break;
	}
	
	cout << endl;
	
	

 
}

