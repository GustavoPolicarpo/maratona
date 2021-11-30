// Author: Gustavo Policarpo
// Name: Joseph’s Cousin
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1032

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define MAX 32750  //MAXIMO VALOR

vector <int> primos;

int j(int n, int i)
{
	int k=primos[i];
	i++;
	if(n==1) return 1;
	int v=(j(n-1,i)+k-1)%n+1;
	/*cout << v << endl;*/
	return v;	
}

int allprimos()
{
	int bp[MAX];
	for (int i=2; i<MAX; i++) bp[i]=1;
	int max=sqrt(MAX);
	for(int i=2; i<max; i++)
	{
		if(bp[i]==1)
		{
			for(int j=i*i; j<MAX; j=j+i)
				bp[j]=0;
		}
	}
	for(int i=2; i<MAX; i++)
		if(bp[i]==1)
			primos.push_back(i);
			
	//cout << primos.size();
}
int main()
{
	allprimos();
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		cout << j(N,0) << endl;
		
	}

return (0);	
}
