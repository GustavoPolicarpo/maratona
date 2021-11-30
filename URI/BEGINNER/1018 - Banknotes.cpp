// Author: Gustavo Policarpo
// Name: Banknotes
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1018

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int VALOR;
int _100, _50, _20, _10, _5, _2, _1;


int main()
{	
	cin >> VALOR;
	
	_100 = VALOR/100;
	_50 = (VALOR-(_100*100))/50;
	_20 = (VALOR-((_100*100)+(_50*50)))/20;
	_10 = (VALOR-((_100*100)+(_50*50)+(_20*20)))/10;
	_5 = (VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)))/5;
	_2 = (VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)+(_5*5)))/2;
	_1 = (VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)+(_5*5)+(_2*2)))/1;
	
	cout << VALOR << endl;
	cout << _100 << " nota(s) de R$ 100,00" << endl;
	cout << _50 << " nota(s) de R$ 50,00" << endl;
	cout << _20 << " nota(s) de R$ 20,00" << endl;
	cout << _10 << " nota(s) de R$ 10,00" << endl;
	cout << _5 << " nota(s) de R$ 5,00" << endl;
	cout << _2 << " nota(s) de R$ 2,00" << endl;
	cout << _1 << " nota(s) de R$ 1,00" << endl;
	
	return(0);
}
