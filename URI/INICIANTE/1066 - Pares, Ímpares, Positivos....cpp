// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pares, Ímpares, Positivos...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1066

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int A, B, C, D, E;
int PO, NE, PA, IM;


int main()
{
	// cout << fixed << setprecision(1);
	cin >> A >> B >> C >> D >> E;
	if(A%2==0) { PA++; 
	}
	else { IM++;
	}
	if(A>0) { PO++;
	}
	else if(A<0){ NE++;
	}
	
	if(B%2==0) { PA++; 
	}
	else { IM++;
	}
	if(B>0) { PO++;
	}
	else if(B<0) { NE++;
	}
	
	if(C%2==0) { PA++; 
	}
	else { IM++;
	}
	if(C>0) { PO++;
	}
	else if(C<0){ NE++;
	}
	
	if(D%2==0) { PA++;
	}
	else { IM++;
	}
	if(D>0) { PO++;
	}
	else if(D<0){ NE++;
	}
	
	if(E%2==0) { PA++; 
	}	
	else { IM++;
	}
	if(E>0) { PO++;
	}
	else if(E<0) { NE++;
	}
	
	cout << PA << " valor(es) par(es)" << endl;
	cout << IM << " valor(es) impar(es)" << endl;
	cout << PO << " valor(es) positivo(s)" << endl;
	cout << NE << " valor(es) negativo(s)" << endl;

return 0;	
}
