// Author: Gustavo Policarpo
// Name: Angry Ducks
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1163

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	double h;
	int p1, p2;
	int n; 
	double a, v, vx, vy, t1, t2, g=9.80665, pi=3.14159, x;
	while(cin >> h >> p1 >> p2 >> n)
	{
		while(n--)
		{
			cin >> a >> v;
			{
				vx=v*cos(a*pi/180);
				vy=v*sin(a*pi/180);
				t1=vy/g;
				t2=(-vy+sqrt(vy*vy+4*g/2*h))/g;
				x=(2*t1+t2)*vx;
				
				if(x>=p1 && x<=p2) cout << fixed << setprecision(5)
				 	<< x <<
					" -> DUCK" << endl;
				else 			   cout << fixed << setprecision(5)
					<< x <<
					" -> NUCK" << endl;		
			}	
		}
		
	}
	
	
	
	
return(0);
}
 

