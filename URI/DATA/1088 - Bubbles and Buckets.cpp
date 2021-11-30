// Author: Gustavo Policarpo
// Name: Bubbles and Buckets
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1088

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

long int P=0;

int N;
int t=0;

int jog(int *b, int i, int j)
{
	int aux = b[i];
    b[i] = b[j];
    b[j] = aux;	
    
    P++;		
}
int main()
{
	while(cin >> N)
	{
		t=0;
		P=0;
		if(N==0) break;
		int a[N];
		int temp;
		
		for(int i=0; i<N; i++)
		{
			cin >> temp;
			a[i]=temp;
		} 
		int i=0;
		while(i<N)
		{
			while(a[i]!=i+1) jog(a, i, a[i]-1);
			i++;
		}
		if(P%2==0) cout << "Carlos" << endl;
		else cout << "Marcelo" << endl;			
	}			
return(0); 
}


