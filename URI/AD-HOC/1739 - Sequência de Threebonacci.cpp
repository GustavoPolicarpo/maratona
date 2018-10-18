// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência de Threebonacci
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1739

#include <bits/stdc++.h>

using namespace std;

int main()
{
	unsigned long long int n;
	unsigned long long int x = 1, y = 1;
	
	stringstream ss;
	vector <unsigned long long int> three;
	three.push_back(3);
	string rep;
	
	int j = 0;
	
	while (j < 60)
	{
		x = x + y;
		y = x - y;
		
		ss.clear();
		
		ss << x;
		ss >> rep;
		
		if (x % 3 == 0 || rep.find("3") != string::npos)
		{
			j++;
			three.push_back(x);
		}
	}
	
	while (cin >> n)
	{
		cout << three[n] << '\n';
	}
	
	return 0;
}

