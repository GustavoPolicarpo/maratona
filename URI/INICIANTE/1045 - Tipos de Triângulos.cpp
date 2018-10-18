// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tipos de Triângulos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1045

# include <iostream>
# include <iomanip>
# include <cmath>

using namespace std;

int main()
{
	double a,b,c;

	cin>>a>>b>>c;

	if((a<b+c)&&(b<c+a)&&(c<a+b)) 
	{
		if((a*a)==(b*b+c*c)||(b*b)==(a*a+c*c)||(c*c)==(a*a+b*b)) cout<<"TRIANGULO RETANGULO"<<endl;
		else if((a*a)>(b*b+c*c)||(b*b)>(a*a+c*c)||(c*c)>(a*a+b*b)) cout<<"TRIANGULO OBTUSANGULO"<<endl;
		else cout<<"TRIANGULO ACUTANGULO"<<endl;
		
		if(a==b&&b==c) cout<<"TRIANGULO EQUILATERO"<<endl;
		else if(a==b||a==c||b==c) cout<<"TRIANGULO ISOSCELES"<<endl;		
	}
	else cout<<"NAO FORMA TRIANGULO"<<endl;
	
return 0;
}


