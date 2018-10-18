// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Praça de Daniel
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1685

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int M[1000][1000];
int SUM[1000][1000];

int matriz_soma(int a, int l)
{
	SUM[0][0]=M[0][0];
	for(int i=1; i<a; i++)
		SUM[i][0]=SUM[i-1][0]+M[i][0];
	for(int j=1; j<l; j++)
		SUM[0][j]=SUM[0][j-1]+M[0][j];
	for(int i=1; i<a; i++)
		for(int j=1; j<l; j++)
			SUM[i][j]=SUM[i-1][j]+SUM[i][j-1]-SUM[i-1][j-1]+M[i][j];	
}

bool achou=false, na=true;
int calculo_tamanho(int a, int l, int k, int me, int MA)
{	//altura, largura, tamanho, menor tamanho, maior tamanho
	///////////////IMPLEMENTAR UM WHILE AQUI!!!!!!!!!!!!!!!
	int melhor_lado=1;
	while(MA-me>1)
	{
		int u=k-1;
		achou=false;
		for(int i=0; i<a-u; i++)
		{
				//cout << k << endl;
			for(int j=0; j<l-u; j++)
			{
				int temp=SUM[i+u][j+u];
					//cout << SUM[i+u][j+u] << "   ";
				if(i>0){ temp-=SUM[i-1][j+u];
					//cout << SUM[i-1][j+u] << "I   ";
				}
				
				if(j>0){ temp-=SUM[i+u][j-1];
					//cout << SUM[i+u][j-1] << "J   ";
				}
				
				if(i>0&&j>0){ temp+=SUM[i-1][j-1];
					//cout << SUM[i-1][j-1] << "B   ";
				}
				
				//cout << temp << endl;
				if(temp==0)
				{
					//cout << i << " " << j << endl;
					achou=true;
					melhor_lado=k;
					me=k;
					k=k+MA/2;
					break;	
				}
			}
			if(achou==true) break;
		}
		if(achou==false)
		{
			MA=k;
			k=(k+me)/2;
		}
	}
	return melhor_lado;

}
vector<int> posl, posc;
int Total;
int salvar_pracas(int a, int l, int k, int ml)
{
	//cout << endl << k << endl;
	Total=0;
	int u=k-1;
	for(int i=0; i<a-u; i++)
	{
		for(int j=0; j<l-u; j++)
		{
			int temp=SUM[i+u][j+u];
			if(i>0)temp-=SUM[i-1][j+u];
			if(j>0)temp-=SUM[i+u][j-1];
			if(i>0&&j>0)temp+=SUM[i-1][j-1];
			if(temp==0)
			{
				Total++;
				posl.push_back(i+1);
				posc.push_back(j+1);
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int n, m;
		posl.clear();
		posc.clear();
		
		cin >> n >> m;
		
		for(int i=0; i<n; i++)
		{
			string t;
			cin >> t;
			for(int j=0; j<m; j++)
			{
				if(t[j]=='*') M[i][j]=1;
				else if(t[j]=='.') M[i][j]=0;	
			}
		}
		matriz_soma(n, m);
		
		
		/*cout << endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				cout << M[i][j] << " ";
			cout << endl;
		}
		
		cout << endl;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<m; j++)
				cout << SUM[i][j] << " ";
			cout << endl;
		}
		*/
		
		
		int ml=(n+m-abs(m-n))/2;
		int k=(ml)/2;
		int usar=calculo_tamanho(n,m,k,0,ml);
		salvar_pracas(n,m,usar,ml);
		
		
		cout << "The side of the square is "
		<< usar << " and the locations are:" << endl;
		for(int i=0; i<posl.size(); i++)
			cout << posl[i] << " " << posc[i] << endl;
		cout << Total << " in total." << endl;				
	}	
		
return 0;
}
