// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Trilhos
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1062

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		int temp;
		while(cin >> temp)
		{
			if(temp==0) break;
			stack <int> trem;
			
			int t[N];
			t[0]=temp;
				
			for(int i=1; i<N; i++)
			{
				int temp; 
				cin >> temp;
				t[i]=temp;
			}
			bool did=false;
			bool take=true;
			int j=0;
			for(int i=1; i<=N; i=i)
			{ 
				if(take==true) trem.push(i);	
				if(!trem.empty()&&trem.top()==t[j])
				{
					trem.pop();
					take=false;
					j++;
				}
				else
				{
					take=true;
					i++;	
				}
						
			}
			if(trem.empty()) cout << "Yes";
			else cout << "No";
			cout << endl;
		}
		cout << endl;
	}	
	
	
return 0;
}
