// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Top N
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1943

#include<bits/stdc++.h>

using namespace std;



int main()
{
	int k;
	cin >> k;
	
	if(k==1) cout << "Top 1" << endl;
	else if(k<=3) cout << "Top 3" << endl;
	else if(k<=5) cout << "Top 5" << endl;
	else if(k<=10) cout << "Top 10" << endl;
	else if(k<=25) cout << "Top 25" << endl;
	else if(k<=50) cout << "Top 50" << endl;
	else if(k<=100) cout << "Top 100" << endl;
		
return(0);
}

