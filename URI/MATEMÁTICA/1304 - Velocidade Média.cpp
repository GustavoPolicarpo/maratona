// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Velocidade Média
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1304

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int TF=0, TI=0, H, M, S; double V=0;
	double DS=0;
	string D;
	while(getline(cin, D))
	{
		
		if(D.size()>=9)
		{
			H=(D[0]-'0')*10+(D[1]-'0');
			M=(D[3]-'0')*10+(D[4]-'0');
			S=(D[6]-'0')*10+(D[7]-'0');	
			TF=TI;
			TI=H*3600+M*60+S;
			DS+=(TI-TF)*V/3600;
			int el=D.size()-10;
			V=0;
			int div=0;
			for(int i=9; i<D.size(); i++) 
			{
				if(D[i]==' ') div++;
				else if(D[i]=='.') div=D.size()-i;
				else 
				{
					V+=(D[i]-'0')*pow(10,el);
					el--;	
				} 
			}
			V=V/(pow(10,div));	
			//cout << V << endl;
		}
		else
		{
			H=(D[0]-'0')*10+(D[1]-'0');
			M=(D[3]-'0')*10+(D[4]-'0');
			S=(D[6]-'0')*10+(D[7]-'0');
			TF=H*3600+M*60+S;
			DS+=(TF-TI)*V/3600;
			TI=TF;

			if(H>9) cout << H << ":";
			else cout << "0" << H << ":";
			
			if(M>9) cout << M << ":";
			else cout << "0" << M << ":";
			
			if(S>9) cout << S << " ";
			else cout << "0" << S << " ";
			
			cout << fixed << setprecision(2) <<
					DS << " km" << endl;	
		}		
		
	}
		
return(0); 
}

