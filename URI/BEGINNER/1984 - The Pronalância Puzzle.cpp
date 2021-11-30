// Author: Gustavo Policarpo
// Name: The Pronalância Puzzle
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1984

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>
#include <cmath>
#include <stack>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

string N;

int main()
{
	cin >> N;
	stack <char> n;
	for(int i=0; i<N.size(); i++ ) n.push(N[i]);
	for(int i=0; i<N.size(); i++ ) 
	{
		cout << n.top();
		n.pop();
	}
	cout << endl;
	
	
	
return(0); 
}

