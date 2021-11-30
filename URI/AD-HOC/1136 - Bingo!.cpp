// Author: Gustavo Policarpo
// Name: Bingo!
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1136

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int N, B;
		
	while(cin >> N >> B)
	{
		if(N==0 && B==0) break;
		
		int gab[N], c[N];
		
		for(int i=0; i<=N; i++)
			gab[i]=i;
			
		for(int i=0; i<=N; i++)
			c[i]=0;

		vector <int> r;
		for(int i=0; i<B; i++)
		{
			int temp;
			cin >> temp;
			c[temp]=1;
			r.push_back(temp);
		}
		sort(r.begin(),r.end());

		bool did=false;
		if(B>N) did=true;
		else if(c[0]==0||c[N]==0) did=false;
		else
		{
			for(int i=0; i<=N; i++)
			{
				did=false;
				for(int j=0; j<B; j++)
				{
					for(int k=0; k<B; k++)
					{		
						//cout << abs(r[j]-r[k])	 << " " << gab[i] << endl;		
						if(abs(r[j]-r[k])==gab[i])
						{
							did=true;
							break;
						}
					}
					if(did==true) break;
				}
				if(did==false) break;
			}	
		}
		if(did==true)
			cout << 'Y' ;

		else
			cout << 'N';
		
		cout << endl;	
	}

return 0;
}
