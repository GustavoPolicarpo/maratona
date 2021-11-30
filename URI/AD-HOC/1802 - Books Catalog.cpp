// Author: Gustavo Policarpo
// Name: Books Catalog
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1802

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	
	vector <int> a, b, c, d, e, tt;
	int A, B, C, D, E, temp, K;
	
	cin >> A; 
	int AA=A;
	while(A--)
	{
		cin >> temp;
		a.push_back(temp);
	}
	
	cin >> B; 
	int BB=B;
	while(B--)
	{
		cin >> temp;
		b.push_back(temp);
	}

	cin >> C; 
	int CC=C;
	while(C--)
	{
		cin >> temp;
		c.push_back(temp);
	}
	
	cin >> D; 
	int DD=D;
	while(D--)
	{
		cin >> temp;
		d.push_back(temp);
	}

	cin >> E; 
	int EE=E;
	while(E--)
	{
		cin >> temp;
		e.push_back(temp);
	}
	
	for(int aa=0; aa<AA; aa++)
	{
		for(int bb=0; bb<BB; bb++)
		{
			for(int cc=0; cc<CC; cc++)
			{
				for(int dd=0; dd<DD; dd++)
				{
					for(int ee=0; ee<EE; ee++)
					{
						tt.push_back(a[aa]+b[bb]+c[cc]+d[dd]+e[ee]);
					}
				}
			}
		}
	}
	sort(tt.begin(), tt.end());
	reverse(tt.begin(), tt.end());
	
	cin >> K;
	int SOMA=0;
	for(int i=0; i<K; i++)
	{
		SOMA+=tt[i];
	}
	cout << SOMA << endl;
	
	

	
		
return(0); 
}

