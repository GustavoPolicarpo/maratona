// Author: Gustavo Policarpo
// Name: Sleds of Santa Claus
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1762

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

 
int main()
{
	 int N;
	 cin >>N;
	 while(N--)
	 {
	 		int n;
	 		cin >> n;
	 		map <string, double> p;
	 		while(n--)
	 		{
	 			cin.ignore();
	 			
	 			string item;
	 			getline(cin, item);
	 			
	 			double peso;
	 			cin >> peso;
	 			
	 			p[item]=round(100*peso);		
			}
			double temp;
			cin >> temp;
			int ptt=round(temp*100);
			
			int pt=0;
			
			string item; int qt; vector<string> inl;
			while(cin.ignore(), getline(cin, item), cin >> qt)
			{
				if(item=="-"&&qt==0) break;
				if(p.count(item))
					pt+=qt*p[item];
				else
					inl.push_back(item);	
			}
			if(!inl.empty())
				for(int i=0; i<inl.size(); i++)
					cout << "NAO LISTADO: " << inl[i] << endl;
				
			cout << "Peso total: " 
			<< fixed << setprecision(2) << double(pt/100.0) 
			<< " kg" << endl;
		
			int nt;
			nt=pt/ptt;
			if(pt%ptt>0) 
				nt++;
			cout << "Numero de trenos: " << nt << endl;
			
			cout << endl;	
	 }
return 0;
}







