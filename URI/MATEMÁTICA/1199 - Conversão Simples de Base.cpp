// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Conversão Simples de Base
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1199

#include<bits/stdc++.h>

using namespace std;

unsigned long long int bk;

void basexto10(string NUMERO, int base)  // conversao de uma base X para a base 10

{
    long long int  U=0, u=0;
	stack <char> n;
	
      for(int i=2; i<NUMERO.size(); i++)   
			{	
				n.push(NUMERO[i]); 
				U=n.top()-48;
				switch(U)
				{
					case 49: U=10; break;  
					case 50: U=11; break; 
					case 51: U=12; break; 
					case 52: U=13; break; 
					case 53: U=14; break; 
					case 54: U=15; break;
					case 17: U=10; break;
					case 18: U=11; break;
					case 19: U=12; break;
					case 20: U=13; break;
					case 21: U=14; break;
					case 22: U=15; break;
				}
				u=u+pow(base, (NUMERO.size()-1-i))*U; 
			}
			
			cout << u;    
}

void base10tox(unsigned long long int decimal, int base)   // conversao de base 10 para uma base X

{
    unsigned long long int quociente, resto;

   if (decimal) 
   {
      quociente = decimal/base;

      resto = decimal%base;
    
      base10tox(quociente, base);

      switch (resto) {

         case 10: putchar('A'); break;
         case 11: putchar('B'); break;
         case 12: putchar('C'); break;
         case 13: putchar('D'); break;
         case 14: putchar('E'); break;
         case 15: putchar('F'); break;
         
         default: cout << resto;
      }  
   }
}


int main () 
{
	int N, cont;
	
	while(1)
	{	
		string IN, tipo; int b;
	
		cin >> IN;
		
		if(IN[0]=='-') break;
		
		else if(IN[1]=='x' || IN[1]=='X')
		{
			b=16;
			basexto10(IN, b);
			cout << endl;	
		}
		
		else
		{
			unsigned long long int num=0;
			
			istringstream aux(IN);
			aux.imbue(locale::classic());
   			aux >> num;
   			
   			
			b=16;
			if(num==0) cout << "0x0" << endl;
   			else
			{
				cout << "0x";
				base10tox(num, b);
				cout << endl;
			}		
		}		
	}
return(0);
}

	
