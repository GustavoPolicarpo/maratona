// Author: Gustavo Policarpo
// Name: Grenais
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1131

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int I, G, N;
int VI, VG, E, NG=1;
bool FIM=false;


int main()
{
	while(FIM==false)
	{
		cin >> I >> G;
		
		if(I>G) { VI++;
		}
		else if (I<G) { VG++;
		}
		else { E++;
		}
		
		cout << "Novo grenal (1-sim 2-nao)" << endl;
		cin >> N;
		
		if(N==1) { NG++; FIM=false;
		}
		else { FIM=true;
		}
	}
	cout << NG << " grenais" << endl;
	cout << "Inter:" << VI << endl;
	cout << "Gremio:" << VG << endl;
	cout << "Empates:" << E << endl;
	if(VI>VG) { cout << "Inter venceu mais" << endl;
		}
	else if (VI<VG) { cout << "Gremio venceu mais" << endl;
	}
	else { cout << "Nao houve vencedor" << endl;
	}
	
	
	
		
return 0;	
}
