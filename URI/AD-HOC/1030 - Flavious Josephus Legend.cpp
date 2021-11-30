// Author: Gustavo Policarpo
// Name: Flavious Josephus Legend
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1030

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;
unsigned int R, S, T, U;

int f(int n, int k){
	
    if(n==1)  return 1;
	
	
    R= f(n-1, k); 
	S=R+k-1;
	T=S%n;
	U=T+1;
	return U;
	
	 
   
}

int main()
{
    unsigned int n, k;
    int NC, i=0;
    cin >> NC;
    while(NC--)
    {
    	i++;
	    cin >> n >> k;
	    cout << "Case " << i << ": " << f(n, k) << endl;
	    
	}
    
}
	
				
	



