// Author: Gustavo Policarpo
// Name: Positive Numbers
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1060

#include <iostream>

using namespace std;

double A, B, C, D, E, F;
int N;

int main()
{
	cin >> A >> B >> C >> D >> E >> F;
	if(A>0) { N++;
	}
	if(B>0) { N++;
	}
	if(C>0) { N++;
	}
	if(D>0) { N++;
	}
	if(E>0) { N++;
	}
	if(F>0) { N++;
	}
	
	cout << N << " valores positivos" << endl;

return 0;	
}
