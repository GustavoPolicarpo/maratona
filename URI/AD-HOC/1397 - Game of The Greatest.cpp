// Author: Gustavo Policarpo
// Name: Game of The Greatest
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1397

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N, A, B, AA, BB;

int main()
{
	while(cin >> N)
	{
		if(N==0) break;
		AA=0; BB=0;
		while(N--)
		{
			cin >> A >> B;
			if(A>B) AA++;
			else if(B>A) BB++;
		}
		cout << AA << " " << BB << endl;
	}
	

return 0;	
}



