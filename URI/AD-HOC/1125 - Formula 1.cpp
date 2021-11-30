// Author: Gustavo Policarpo
// Name: Formula 1
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1125

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int G, P;
	while(cin >> G >> P)
	{
		if(G==0&&P==0) break;
 		int M[G][P];
		int m[P];
		for(int i=0; i<G; i++)	
			for(int j=0; j<P; j++)
			{
				int temp;
				cin >> temp;
				M[i][j]=temp;
			}
		int C;
		cin >> C;
		while(C--)
		{
			for(int i=0; i<P; i++)
				m[i]=0;	
					
			int c;
			cin >> c;
			int p[c];
			for(int i=0; i<c; i++)
			{
				int temp;
				cin >> temp;
				p[i]=temp;	
			}	
					
			for(int i=0; i<G; i++)	
			{
				int k=1;
				for(int j=0; j<P; j++)
				{
					if(M[i][j]==k)
					{
						m[j]+=p[k-1];
						k++;
						j=-1;
						if(k>c) break;
					}
				}
			}		
			int W=0;		
			for(int i=0; i<P; i++)
				if(W<m[i])W=m[i];
						
			int mark=0;
			for(int i=0; i<P; i++)
			{
				if(m[i]==W)
				{
					if(mark!=0)
						cout << " " << i+1;
					else
					{
						cout << i+1;
						mark=1;
					}
				}
			}
			cout << endl;	
		}
	}
	
	
	
return 0;
}





