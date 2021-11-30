// Author: Gustavo Policarpo
// Name: Functions
// Level: 1
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1555

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int N;
int X, Y;
int R, B, C;
int M;

int main()
{
	cin >> N;
	for(int i=1; i<=N; i++)
	{
		cin >> X >> Y;
		R=pow((3*X),2)+Y*Y;
		B=2*X*X+pow((5*Y),2);
		C=-100*X+Y*Y*Y;
		M=(R+B+abs(R-B))/2;
		M=(M+C+abs(M-C))/2;
		if(M==R) cout << "Rafael ganhou" << endl;
		else if(M==B) cout << "Beto ganhou" << endl;
		else if(M==C) cout << "Carlos ganhou" << endl;
		R=0; B=0; C=0; 		
	}
	
	
return (0);
}
