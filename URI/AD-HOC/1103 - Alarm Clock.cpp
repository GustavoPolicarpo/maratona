// Author: Gustavo Policarpo
// Name: Alarm Clock
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1103

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int H1, H2, M1, M2, T1, T2, TF;;


int main()
{
	while(1)
	{
		cin >> H1 >> M1 >> H2 >> M2;
		if(H1==0 && H2==0 && M1==0 && M2==0) break;
		T1=H1*60+M1;
		T2=H2*60+M2;
		if(T2<T1) TF=T2+60*24-T1;
		else TF=T2-T1;
		cout << TF << endl;
		
	}
	
	
			
				
			
	
return(0); 
}

