// Author: Gustavo Policarpo
// Name: Even Between five Numbers
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1065

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int A, B, C, D, E;
int N;


int main()
{
	// cout << fixed << setprecision(1);
	cin >> A >> B >> C >> D >> E;
	if(A%2==0) { N++; 
	}
	if(B%2==0) { N++; 
	}
	if(C%2==0) { N++; 
	}
	if(D%2==0) { N++;
	}
	if(E%2==0) { N++; 
	}	
	
	cout << N << " valores pares" << endl;

return 0;	
}
