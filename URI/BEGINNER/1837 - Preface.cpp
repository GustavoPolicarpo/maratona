// Author: Gustavo Policarpo
// Name: Preface
// Level: 7
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1837

#include <iostream>
#include <cmath>

using namespace std;

int q, r, a, b;

int main()
{
	
	cin >> a>> b;	
	
	r=a%b;
	q=(a-r)/b;
	
	if(abs(a)==abs(b))
	{
		r=0;
		q=(a-r)/b;
	}
	else if(a<0 && b<0 )
	{
		if(r==0)
		{
			r=a%b;
			q=(a-r)/b;	
		}
		else
		{
			r=abs(b-r);
			q=(a-r)/b;
		}
		
	}
	else if(a<0 && b>0)
	{
		if(a<b && r<0) 
		{
			q=q-1;
			r=a-b*q;
		}
		else
		{
			r=a%b;
			q=(a-r)/b;
		}
		
	}
	else if (a<0)
	{
		r=b-abs(r);
		q=(a-r)/b;
	}
	else
	{
		r=a%b;
		q=(a-r)/b;
	}
	

	cout << q << " " << r << endl;		
		


return(0);
}

