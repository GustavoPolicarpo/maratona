// Author: Gustavo Policarpo
// Name: Whose Turn Is It?
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1914

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int QT;
long int N, M, S;
string A, a, B, b, c;


int main()
{
	cin >> QT;
	while(QT--)
	{
		cin >> A >> a >> B >> b;
		
		cin >> N >> M;
		S=N+M;
		if(S%2==0) c="PAR";
		else c="IMPAR";
		
		//cout << N << " " << M << " " << A << " " << a << "" << B << " " << b << " " << c << endl;
		if(a==c) cout << A << endl;
		else cout << B << endl;
		
		A=""; B=""; a=""; b=""; c=""; N=0; M=0;
	}
		
	return 0;
}
