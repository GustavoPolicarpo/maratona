// Author: Gustavo Policarpo
// Name: URI
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1787

#include<bits/stdc++.h>

using namespace std;

bool potencia(int x)
{
	if(x==1) return false;
	else return (pow(2,int(log2(x)))==x);	
}


int main()
{
	int N;
	while(1)
	{
		cin >> N;
		if(N==0) break;
		
		int PA=0, PB=0, PC=0;
		long int A, B, C;
		
		
		while(N--)
		{
			long int M=0;
			
			cin >> A >> B >> C;
			M=(A+B+abs(A-B))/2;
			M=(M+C+abs(M-C))/2;
		
			if(potencia(A)==true)
			{
				PA++;
				if(A==M) PA++;	
			} 
			if(potencia(B)==true) 
			{
				PB++;
				if(B==M) PB++;	
			}
			if(potencia(C)==true) 
			{
				PC++;
				if(C==M) PC++;	
			}	
		}
		if(PA>PB&&PA==PC || PA>PC&&PA==PB || PB>PA&&PB==PC || PA==PB&&PB==PC) cout << "URI" << endl;
		else if(PA>PB && PA>PC) cout << "Uilton" << endl;
		else if(PB>PA && PB>PC) cout << "Rita" << endl;
		else if(PC>PA && PC>PB) cout << "Ingred" << endl;
	}	
return(0);
}

