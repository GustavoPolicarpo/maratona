// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ida à Feira
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1281

# include <bits/stdc++.h>

using namespace std;

int main()
{

	int N;
	cin >> N;
	while(N--)
	{
		int a;
		cin >> a;
		vector <string> n;
		vector <double >p;
		while(a--)
		{
			string t; double pr;
			cin >> t >> pr;
			n.push_back(t);
			p.push_back(pr);
		}
		cin >> a;
		double tt=0;
		while(a--)
		{
			string t; int q;
			cin >> t >> q;
			for(int i=0; i<n.size(); i++)
			{
				if(t==n[i])
				{
					tt+=p[i]*q;
				}
					
			}
		}
		cout << "R$ " << fixed << setprecision(2) << tt << endl;
		
	}


	return 0;
}
