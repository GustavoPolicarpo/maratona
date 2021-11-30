// Author: Gustavo Policarpo
// Name: Positives and Average
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1064

#include <iostream>
#include <iomanip>

using namespace std;

double A, B, C, D, E, F;
int N;
double M;

int main()
{
	cout << fixed << setprecision(1);
	cin >> A >> B >> C >> D >> E >> F;
	if(A>0) { N++; M=M+A;
	}
	if(B>0) { N++; M=M+B;
	}
	if(C>0) { N++; M=M+C;
	}
	if(D>0) { N++; M=M+D;
	}
	if(E>0) { N++; M=M+E;
	}
	if(F>0) { N++; M=M+F;
	}
	
	M=M/N;
	
	cout << N << " valores positivos" << endl;
	cout << M << endl;

return 0;	
}
