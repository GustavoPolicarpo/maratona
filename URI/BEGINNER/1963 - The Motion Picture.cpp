// Author: Gustavo Policarpo
// Name: The Motion Picture
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1963

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>
#include <cmath>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

double A, B, S;


int main()
{
	cin >> A >> B;
	
	S=B-A;
	S=S/A*100;
	
	cout << fixed << setprecision(2) << S << "%" << endl;
	
 
}

