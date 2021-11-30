// Author: Gustavo Policarpo
// Name: Pokémon!
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1836

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int C;
	cin >> C;
	for(int i=1; i<=C; i++)
	{
		string N; int L;
		cin >> N >> L;
		vector <int> att;
		
		int BS, IV, EV;
		cin >> BS >> IV >> EV;
		int temp=(IV+BS+sqrt(EV)/8+50)*L/50+10;
		att.push_back(temp);
		for(int j=0; j<3; j++)
		{
			int BS, IV, EV;
			cin >> BS >> IV >> EV;
			int temp=(IV+BS+sqrt(EV)/8)*L/50+5;
			att.push_back(temp);
		}
		cout
		<<"Caso #"<<i<<": "<<N<<" nivel "<<L<<endl
		<<"HP: "<<att[0]<<endl 
		<<"AT: "<<att[1]<<endl
		<<"DF: "<<att[2]<<endl
		<<"SP: "<<att[3]<<endl;
	}
	
	
return(0); 
}


