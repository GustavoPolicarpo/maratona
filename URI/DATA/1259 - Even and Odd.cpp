// Author: Gustavo Policarpo
// Name: Even and Odd
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1259

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int N;
	cin >> N;
	vector <int> i, p;	
	while(N--)
	{
		int temp;
		cin >> temp;
		if(temp%2==0) p.push_back(temp);
		else i.push_back(temp);
	}
	sort (p.begin(), p.end());
	sort(i.begin(), i.end());
	reverse(i.begin(), i.end());
	for(int i=0; i<p.size(); i++)
		cout << p[i] << endl;
	for(int j=0; j<i.size(); j++)
		cout << i[j] << endl;
	
	
return(0);
}
