// Author: Gustavo Policarpo
// Name: Factorial Again!
// Level: 1
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1429

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int go(int fat)
{
	if(fat==1) return 1;
	else return fat*go(fat-1);
	
	
}
 
int main()
{
        int tam;
        string N;
 
 
        while(1)
        {
        	cin >> N;
        	if(N=="0") break;
        	
        	tam=N.size();
        	int u;
        	long int U=0, res=0;
        	
        	stack <char> n;
        	for(int i=0; i<tam; i++)
        	{
        		n.push(N[i]);
        		u=n.top()-48;
        		res=go(tam-i);
        		
        		U=U+u*res;	     		
			}
			
			cout << U << endl;		
             
        }
 
        return 0;
}
