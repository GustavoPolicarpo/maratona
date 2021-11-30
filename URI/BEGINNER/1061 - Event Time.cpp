// Author: Gustavo Policarpo
// Name: Event Time
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1061

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

string nada;
int DI, HI, MI, SI, TI;
int DF, HF, MF, SF, TF;
int TT;

int main()
{
	cin >> nada >> DI;
	cin >> HI >> nada >> MI >> nada >> SI;
	cin >> nada >> DF;
	cin >> HF >> nada >> MF >> nada >> SF;
	
	TF=DF*86400+HF*3600+MF*60+SF;
	
	TI=DI*86400+HI*3600+MI*60+SI;
	
	TT=TF-TI;
	
	cout << int(TT/86400) << " dia(s)" << endl << int((TT%86400)/3600) << " hora(s)" << endl
	<< int((TT%86400%3600)/60) << " minuto(s)" << endl <<  int((((TT%86400)%3600)%60)/1) << " segundo(s)" << endl;

return(0);	
		
}
