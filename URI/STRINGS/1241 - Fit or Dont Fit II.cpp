// Author: Gustavo Policarpo
// Name: Fit or Dont Fit II
// Level: 2
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1241

#include <iostream>
#include <stack>
#include <cmath>

using namespace std;

int N;
string A, B;
int cont;

int main ()
{
	cin >> N;
	for( cont=1; cont<=N; cont++)
	{
		cin >> A >> B;
		stack <char> a, b;
		
		for (int i=0; i<A.size(); i++)
      	a.push(A[i]);
      	
      	for (int i=0; i<B.size(); i++)
     	b.push(B[i]);
     	
    while(1)
    {
      if (a.empty() && !b.empty())
      {
         cout << "nao encaixa" << endl;
         break;
      }

      else if (!a.empty() && b.empty())
      {
         cout << "encaixa" << endl;
         break;
      }

      else if (a.empty() && b.empty())
      {
         cout << "encaixa" << endl;
         break;
      }

      if (a.top() != b.top())
      {
         cout << "nao encaixa" << endl;
         break;
      }

      a.pop();
      b.pop();
   }
    
	}
	

return (0);   
}


