// Author: Gustavo Policarpo
// Name: Our Days Are Never Coming...
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1864

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N; 
char F[35];
string FF;
stack <char> f;


int main()
{
	FF="LIFE IS NOT A PROBLEM TO BE SOLVED";
	for (int i=33; i>=0; i--) f.push(FF[i]);
	for (int i=0; i<34; i++)
	{
		F[i]=f.top();
		f.pop();
	}
	cin >> N ;
	for (int i=0; i<N; i++) cout << FF[i];
	cout << endl;
	

	
	
	return 0;
}
