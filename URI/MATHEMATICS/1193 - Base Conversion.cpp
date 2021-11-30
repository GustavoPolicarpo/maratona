// Author: Gustavo Policarpo
// Name: Base Conversion
// Level: 3
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1193

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, cont;
	cont = 0;
	char alfa[] = {"0123456789abcdef"}; 
	
	cin >> N;
	while(N--)
	{
		char n[255]; string t, bx;
		long long b10, bk;;
		cont ++;
		
		cin >> n >> t;
		
		/**************************************************************/
		if(t=="bin")
		{
			cout << "Case " << cont << ":" << endl;
			
			b10 = strtol(n, NULL, 2);
			cout << b10 << " dec" << endl;
			
			//bk=b10;
			
			while(b10)
			{
				bx += alfa [b10%16];
				b10 /= 16;
			}
			reverse( bx.begin(), bx.end() );
			cout << bx << " hex" << endl;		
		}
		/**************************************************************/
		else if(t=="dec")
		{
			cout << "Case " << cont << ":" << endl;
			
			b10 = strtol(n, NULL, 10);
			bk=b10;
			
			while(b10)
			{
				bx += alfa [b10%16];
				b10 /= 16;
			}
			reverse( bx.begin(), bx.end() );	
			cout << bx << " hex" << endl;
			
			b10=bk;
			bx="";
			
			while(b10)
			{
				bx += alfa [b10%2];
				b10 /= 2;
			}
			reverse( bx.begin(), bx.end() );
			cout << bx << " bin" << endl;	
		}
		/**************************************************************/
		else if(t=="hex")
		{
			cout << "Case " << cont << ":" << endl;
			
			b10 = strtol(n, NULL, 16);
			cout << b10 << " dec" << endl;
			
			//bk=b10;
			
			while(b10)
			{
				bx += alfa [b10%2];
				b10 /= 2;
			}
			reverse( bx.begin(), bx.end() );
			cout << bx << " bin" << endl;		
		}
		cout << endl;
	}
return(0);
}
