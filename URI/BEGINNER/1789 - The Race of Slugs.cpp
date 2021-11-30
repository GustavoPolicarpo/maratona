// Author: Gustavo Policarpo
// Name: The Race of Slugs
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1789

#include <iostream>
#include <cmath>

using namespace std;

int L, V, M;

int main()
{
	while(cin >> L)
	{
		M=0;
		while(L--) 
		{
			cin >> V;
			if(V>M) M=V;
		}
		if(M<10) cout << "1" << endl;
		else if(M<20) cout << "2" << endl;
		else cout << "3" << endl;	
	}	
return(0);
}

