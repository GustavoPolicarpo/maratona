// Author: Gustavo Policarpo
// Name: Theon's Answer
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1858

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N; 
int T[101];
int M=20, NM;
int i;

int main()
{
	cin >> N ;
	for(i=1; i<=N; i++)
	{
		cin >> T[i];
		if(M>T[i]) 
		{
			M=T[i];
			NM=i;			
		}
	}
	cout << NM << endl;

	
	return 0;
}
