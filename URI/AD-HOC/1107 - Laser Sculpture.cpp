// Author: Gustavo Policarpo
// Name: Laser Sculpture
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1107

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{		
	int A, C;
	while(cin>>A>>C)
	{
		if(A==0&&C==0) break;
		int h[C];
		for(int i=0; i<C; i++)
			cin >> h[i];
		int x=A-h[0];
		for(int i=1; i<C; i++)
			if(h[i]<h[i-1])
				x+=h[i-1]-h[i];	
		cout << x << endl;
	}
return (0);	
}
