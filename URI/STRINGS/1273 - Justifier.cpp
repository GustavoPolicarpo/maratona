// Author: Gustavo Policarpo
// Name: Justifier
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1273

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int N, mark = 0;
	while(cin >> N)
	{
		
		if(N==0) break;
		string T; vector<string>t; int tam=0;
		while(N--)
		{
			cin >> T;
			if(T.size()>tam) tam=T.size();
			t.push_back(T);	
		}
		if(mark!=0)
            cout<<endl;
        else
            mark = 1;
		for(int i=0; i<t.size(); i++)
		{
			cout << setw(tam) << t[i] << endl;;	
		}
		t.clear();	
	}
	
return(0); 
}


