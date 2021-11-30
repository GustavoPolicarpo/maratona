// Author: Gustavo Policarpo
// Name: Ballot Evaluation
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1635

# include <bits/stdc++.h>

using namespace std;

int main()
{
	map <string, int> l;
	
	int p; int a;
	cin >> p >> a;
	while(p--)
	{
		string pt; double at;
		cin >> pt;
		cin >> at;
		l[pt]=round(at*10);	
	}
	for(int i=1; i<=a; i++)
	{
		vector <string> op;
		string c=" ";
		while(c!="<"&&c!=">"&&c!="="&&c!="<="&&c!=">=")
		{
			cin >> c;
			op.push_back(c);
		}
		int chute;
		
		cin >> chute;
		chute*=10;
		
		int value=0;
		for(int j=0; j<op.size()-1; j++)
		{
			//cout << (l[op[j]]) << endl;
			value+=(l[op[j]]);
		}
		//cout << value << endl;
		
		bool did=false;
		string go=op[op.size()-1];
		if(go=="<"&&value<chute)
			did=true;
		else if(go==">"&&value>chute)
			did=true;
		else if(go=="<="&&value<=chute)
			did=true;
		else if(go==">="&&value>=chute)
			did=true;
		else if(go=="="&&value==chute)
			did=true;
			
		cout << "Guess #" << i;
		if(did==true)
			cout << " was correct.";
		else
			cout << " was incorrect.";
		cout << endl;
	}
	l.clear();

return 0;
}
