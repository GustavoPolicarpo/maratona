// Author: Gustavo Policarpo
// Name: Head or Tail
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1329

#include <iostream>
#include <iomanip>

using namespace std;


int N=1, R;
int M, J;


int main()
{
	while(1)
	{
		M=0; J=0;
		cin >> N;
		if(N==0) break;
		while(N--)
		{
			cin >> R;
			if(R==0) M++;
			else if(R==1) J++;		
		}
		cout << "Mary won " << M << " times and John won " << J << " times" << endl;
				
	}

return 0;	
}
