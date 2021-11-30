// Author: Gustavo Policarpo
// Name: Triangle
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1929

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int A, B, C, D;
int main()
{
	cin >> A >> B >> C >> D;
	if(A<B+C && B<A+C && C<A+B) cout << 'S' << endl;
	else if(D<B+C && B<D+C && C<D+B) cout << 'S' << endl;
	else if(A<D+C && D<A+C && C<A+D) cout << 'S' << endl;
	else if(A<B+D && B<A+D && D<A+B) cout << 'S' << endl;
	else cout << 'N' << endl;
		
	return 0;
}
