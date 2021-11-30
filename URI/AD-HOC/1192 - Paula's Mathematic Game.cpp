// Author: Gustavo Policarpo
// Name: Paula's Mathematic Game
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1192

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
	



