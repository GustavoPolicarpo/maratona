// Author: Gustavo Policarpo
// Name: Welcome to the Winter!
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1847

#include <iostream>
#include <cmath>

using namespace std;

int t1, t2, t3;

int main()
{

	cin >> t1 >> t2 >> t3;
	if(t2<t1)
	{
		if(t3>t2) cout << ":)" << endl;
		else if(abs(t3-t2)<abs(t2-t1)) cout << ":)" << endl;
		else if(abs(t3-t2)>=abs(t2-t1)) cout << ":(" << endl;
	}
	else if(t2>t1)
	{
		if(t3<t2) cout << ":(" << endl;
		else if(abs(t3-t2)>=abs(t2-t1)) cout << ":)" << endl;
		else if(abs(t3-t2)<abs(t2-t1)) cout << ":(" << endl;	
	}
	else if(t2==t1)
	{
		if(t3<t2) cout << ":(" << endl;
		else if(t3>t2) cout << ":)" << endl;
		else cout << ":(" << endl;
	}

return(0);
}

