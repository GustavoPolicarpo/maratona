// Author: Gustavo Policarpo
// Name: Area
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1012

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A, B, C, ATRI, ACIR, ATRA, AQUA, ARET;
double pi=3.14159;


int main()
{	
	cin >> A >> B >> C;
	
	ATRI = A*C/2.0;
	ACIR = pi*C*C;
	ATRA = (A+B)*C/2;
	AQUA = pow(B,2);
	ARET = A*B;
	
	cout << fixed << setprecision(3);
	cout << "TRIANGULO: "<< ATRI << endl;
	cout << "CIRCULO: "<< ACIR << endl;
	cout << "TRAPEZIO: "<< ATRA << endl;
	cout << "QUADRADO: "<< AQUA << endl;
	cout << "RETANGULO: "<< ARET << endl;
	
	return(0);
}
