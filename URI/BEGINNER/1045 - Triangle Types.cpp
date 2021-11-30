// Author: Gustavo Policarpo
// Name: Triangle Types
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1045

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double I1, I2, I3;
long double A, B, C;

int main()
{	
	cin >> I1 >> I2 >> I3;
	
	//colocando em ordem as entradas
	if ((I1==I2 && I1!=I3) || (I1!=I2 && I1==I3))
	{
		if(I1>I3)
		{
			A=I1; B=I2; C=I3;
		}
		else if(I1<I3)
		{
			C=I1; B=I2; A=I3;
		}
		else if (I1>I2)
		{
			A=I1; B=I3; C=I2; 
		}
		else if(I1<I2)
		{
			C=I1; B=I3; A=I2;
		}
	}
	else if ((I2==I3 && I2!=I1) || (I2!=I3 && I2==I1))
	{
		if(I2>I1)
		{
			A=I2; B=I3; C=I1;
		}
		else if(I2<I1)
		{
			C=I3; B=I2; A=I1;
		}
		else if (I2>I3)
		{
			A=I2; B=I1; C=I3; 
		}
		else if(I2<I3)
		{
			C=I2; B=I3; A=I1;
		}
	}
	else if (I1==I2 && I1==I3)
	{
		A=I1, B=I2, C=I3;	
	}
	
	if (I1<I2 && I1<I3)
	{
		C=I1;
	}
	else if (I1>I2 && I1>I3)
	{
		A=I1;
	}
	else if ((I1>I2 && I1<I3) || (I1<I2 && I1>I3))
	{
		B=I1;
	}
	
	if (I2<I1 && I2<I3)
	{
		C=I2;
	}
	else if (I2>I1 && I2>I3)
	{
		A=I2;
	}
	else if ((I2>I1 && I2<I3) || (I2<I1 && I2>I3))
	{
		B=I2;
	}	
	
	if (I3<I1 && I3<I2)
	{
		C=I3;
	}
	else if (I3>I1 && I3>I2)
	{
		A=I3;
	}
	else if ((I3>I1 && I3<I2) || (I3<I1 && I3>I2))
	{
		B=I3;
	}	
			
	//verificando os tipos de triangulo
    if(A>=B+C)
	{
		cout << "NAO FORMA TRIANGULO" << endl;
	}
	else if((A*A)==B*B+C*C)
	{
		cout << "TRIANGULO RETANGULO" << endl;
	}
	else if (A*A>B*B+C*C)
	{
		cout << "TRIANGULO OBTUSANGULO" << endl;
	}
	else if (A*A<B*B+C*C)
	{
		cout << "TRIANGULO ACUTANGULO" << endl;
	}
	
	if (A==B && A==C)
	{
		
		cout << "TRIANGULO EQUILATERO" << endl;
	}
	else if((A==B && A!=C) || (A!=B && A==C))
	{
		cout << "TRIANGULO ISOSCELES" << endl;
	}
	else if((B==C && B!=A) || (B!=C && B==A))
	{
		cout << "TRIANGULO ISOSCELES" << endl;
	}
				
	return(0);
}
