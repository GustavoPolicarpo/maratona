// Author: Gustavo Policarpo
// Name: Fibonacci, How Many Calls?
// Level: 4
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1029

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int counter, call;
 
int fibonacci(int n)
{
		
        if(n == 0)
		{
                call++;
                return 0;
        }
		else if(n == 1)
		{
                call++;
                counter++;
                return 1;
        }
		else
		{
                call++;
                return fibonacci(n - 1) + fibonacci(n - 2);
        }
}
 
int main()
{
        int N, x, res;
 
        cin >> N;
 
        while(N--)
        {
                counter = 0;
                call = 0;
                cin >> x;
            
 
                res = fibonacci(x);
                
                
                cout << "fib(" << x << ") = " << call-1 << " calls = " << counter << endl;
        }
 
        return 0;
}
