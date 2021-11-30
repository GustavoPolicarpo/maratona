// Author: Gustavo Policarpo
// Name: Monetary Formatting
// Level: 4
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1309

#include<bits/stdc++.h>

using namespace std;

int main()
{
	string d, c;
	int cont;
	while(cin >> d >> c)
	{
		cont=0;
		stack <char> go;
		string out;
		
		cout << "$";
		
		for(int i=d.size()-1; i>=0; i--)
		{
			go.push(d[i]);
			out += go.top();
			cont++;
			if(cont==3 && i!=0) 
			{
				cont=0; 
				out += ",";
			}	
		}
		reverse( out.begin(), out.end() );	
		cout << out << ".";
		
		if(c.size()>1) cout << c << endl;
		else cout << "0" << c << endl;	
	}
	
return(0);
}

