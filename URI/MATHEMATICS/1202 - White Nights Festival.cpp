// Author: Gustavo Policarpo
// Name: White Nights Festival
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1202

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int M[2][2];
vector <int> A, B, C;

int fib(int j)
{
	int mm[2][2];
	mm[0][0]=A[j]; mm[1][0]=B[j];  mm[1][1]=C[j];
	if(C[j]==0) mm[1][1]=0;
	
	//cout << mm[0][0] << "   " << mm[1][0] << endl << mm[1][0] << "   " << mm[1][1] << endl << endl;
	int temp=M[0][0], temp2=M[1][0], temp3=M[1][1];
	M[0][0]=(temp*mm[0][0]+temp2*mm[1][0])%1000;
	M[1][0]=(temp*mm[1][0]+temp2*mm[1][1])%1000;
	M[1][1]=(temp2*mm[1][0]+temp3*mm[1][1])%1000;
	//cout << "         " << M[0][0] << "   " << M[1][0] << endl << "         " << M[1][0] << "   " << M[1][1] << endl << endl;
}

int main()
{
	int m[2][2];
	m[0][0]=1; m[1][0]=1; m[1][1]=0;
	
	A.push_back(0);
	A.push_back(m[0][0]);
	
	B.push_back(0);
	B.push_back(m[1][0]);
	
	C.push_back(0);
	C.push_back(m[1][1]);
	
	for(int i=0; i<=10000; i++)
	{
		int temp=m[0][0], temp2=m[1][0], temp3=m[1][1];
		m[0][0]=(temp*temp+temp2*temp2)%1000;
		m[1][0]=(temp*temp2+temp2*temp3)%1000;
		m[1][1]=(temp2*temp2+temp3*temp3)%1000;
		A.push_back(m[0][0]);
		B.push_back(m[1][0]);
		C.push_back(m[1][1]);
	}
	
	/*for(int i=0; i<=50; i++) //cout << i << "  " << B[i] << "  " << A[i] << endl;
	{
		cout << A[i] << "   " << B[i] << endl << B[i] << "   " << C[i] << endl << endl;
	}*/
	
	int n;
	cin >> n;
	while(n--)
	{
		string t;
		cin >> t;
		int tam=t.size()-1;
		bool first=true;
		for(int i=0; i<=tam; i++)
		{
			int u=tam-i+1;
			if(t[i]=='1' && first==true) 
			{
				M[0][0]=A[u]; M[1][0]=B[u]; M[1][1]=C[u];
				if(C[u]==0) M[1][1]=0;
				//cout << M[0][0] << " " << M[1][0] << endl << M[1][0] << "   " << M[1][1] << endl << endl;
				first=false;
			}	
			else if(t[i]=='1')
				fib(u);
		}
		int out=M[1][0];
		if(out<10) cout << "00";
		else if(out<100) cout << "0";
		cout << out << endl;
		
	}
	
	
	
	
	
}
