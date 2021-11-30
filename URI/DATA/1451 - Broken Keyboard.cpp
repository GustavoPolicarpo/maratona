// Author: Gustavo Policarpo
// Name: Broken Keyboard
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1451

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;




int main()
{
	string T;
	while(cin >> T)
	{
		deque <char> t2, t1;
		deque <string> t;
		string c="";
		
		int p=1;
		for(int i=0; i<T.size(); i++)
		{
			if(T[i]=='[')
			{
				if(p==1)
					t.push_front(c);
				else
					t.push_back(c);
					
				p=1;
				c="";
			}
					
					
				 
			else if(T[i]==']')
			{
				if(p==1)
					t.push_front(c);
				else
					t.push_back(c);
				p=-1;
				c="";
			}
			else
				c+=T[i];
		}
		if(p==1)
			t.push_front(c);
		else
			t.push_back(c);
			
		for(int i=0; i<t.size(); i++)
			cout << t[i];
		
		cout << endl;
			
	}
	

return 0;
}
