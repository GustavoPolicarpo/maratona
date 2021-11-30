// Author: Gustavo Policarpo
// Name: Encryption
// Level: 5
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1024

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <string.h>
#include <cctype>
#include <cstdlib>

using namespace std;

int N;
char M[1000];
stack <char> m;
char T;
string O;



int main()
{
	cin >> N;
	cin.ignore();
	while(N--)
	{
		cin.getline(M,1000);
		for(int i=0; i<strlen(M); i++) m.push(M[i]);
		for(int i=0; i<strlen(M); i++)
		{
			
			T=m.top();
			if(isalpha(T)) T=T+3;
			
			if(i>=strlen(M)/2)
			{
				T=T-1;
			}
			O=O+T;
			m.pop();
		}
		cout << O << endl;
		
		O="";	
	}

return 0;

}
