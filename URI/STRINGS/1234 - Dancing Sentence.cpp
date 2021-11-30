// Author: Gustavo Policarpo
// Name: Dancing Sentence
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1234

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <string.h>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

char T[51];
char O;
stack <char> t;
int i;
bool up = false;


int main()
{
	while(cin.getline (T, 51))
	{
		for( i=0; i<strlen (T); i++) t.push(T[i]);
		char TT[strlen(T)];
		
		for(i=i-1; i>=0; i--)
		{
			O=t.top();
			t.pop();
			T[i]=O;
		}
		i=0;
		while(1)
		{
			if(isupper(T[i])) { up=true;  break; }
			else if(islower(T[i])) { up=true; break; }
			i++;
		}
		for(i=0; i<strlen (T); i++)
		{	
			if(isupper (T[i]) && up==false) { T[i]=T[i]+32; up=true; }
			else if(islower (T[i]) && up==false ) { T[i]=T[i]; up=true; }
			else if(islower (T[i]) && up==true ) { T[i]=T[i]-32; up=false; }
			else if(isupper (T[i]) && up==true ) { T[i]=T[i]; up=false; }
		}
		
		cout << T << endl;
			
		
	}

return 0;
}


