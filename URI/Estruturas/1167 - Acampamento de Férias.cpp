// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Acampamento de Férias
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1167

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		int bk=N;
		
		vector <int> n;
		vector <string> t;
		while(N--)
		{
			string stemp; int ntemp;
			cin >> stemp >> ntemp;
			t.push_back(stemp);
			n.push_back(ntemp);
		}	
		int p;
		int rem=n[0];
		if(rem%2==0)
			p=bk-1;
		else 
			p=1;

		while(t.size()>1)
		{
			if(rem%2==1)
			{
				rem--;
				while(rem--)
				{
					p++;
					if(p>=bk) p=0;
				}
			}
			else if(rem%2==0)
			{
				rem--;
				while(rem--)
				{	
					p--;
					if(p<=-1) p=bk-1;	
				}
			}
			rem=n[p];
			t.erase(t.begin()+ p);
			n.erase(n.begin()+ p);
			bk--;
			if(rem%2==1)
			{
				if(p>=bk) p=0;
			}
			if(rem%2==0)
			{
				p--;		
				if(p<=-1) p=bk-1;
			}
		}
		cout << "Vencedor(a): " << t[0] << endl;	
	}	
	
return 0;
}
