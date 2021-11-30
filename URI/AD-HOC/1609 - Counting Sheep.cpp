// Author: Gustavo Policarpo
// Name: Counting Sheep
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1609

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	cin >> N;
	set <long int> carneiro;
	while(N--)
	{
		carneiro.clear();
		int n;
		cin >> n;
		while(n--)
		{
			int temp; cin >> temp;
			carneiro.insert(temp);
		}
		cout << carneiro.size() << endl;	
	}		
}
