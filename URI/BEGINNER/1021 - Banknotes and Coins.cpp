// Author: Gustavo Policarpo
// Name: Banknotes and Coins
// Level: 6
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1021

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double VALOR;
int _100, _50, _20, _10, _5, _2;
int _1, _050, _025, _010, _005, _001;


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
	_050 = (VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)+(_5*5)+(_2*2)+(_1*1)))/0.50;
	_025 = (VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)+(_5*5)+(_2*2)+(_1*1)+(_050*0.50)))/0.25;
	_010 = (VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)+(_5*5)+(_2*2)+(_1*1)+(_050*0.50)+(_025*0.25)))/0.10;
	_005 = (VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)+(_5*5)+(_2*2)+(_1*1)+(_050*0.50)+(_025*0.25)+(_010*0.10)))/0.05;
	_001 = (VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)+(_5*5)+(_2*2)+(_1*1)+(_050*0.50)+(_025*0.25)+(_010*0.10)+(_005*0.05)))/0.01;
	
	if ((VALOR-((_100*100)+(_50*50)+(_20*20)+(_10*10)+(_5*5)+(_2*2)+(_1*1)+(_050*0.50)+(_025*0.25)+(_010*0.10)+(_005*0.05)+(_001*0.01)))>=0.009) { _001++;}
	
	cout << "NOTAS:" << endl;
	cout << _100 << " nota(s) de R$ 100.00" << endl;
	cout << _50 << " nota(s) de R$ 50.00" << endl;
	cout << _20 << " nota(s) de R$ 20.00" << endl;
	cout << _10 << " nota(s) de R$ 10.00" << endl;
	cout << _5 << " nota(s) de R$ 5.00" << endl;
	cout << _2 << " nota(s) de R$ 2.00" << endl;
	cout << "MOEDAS:" << endl;
	cout << _1 << " moeda(s) de R$ 1.00" << endl;
	cout << _050 << " moeda(s) de R$ 0.50" << endl;
	cout << _025 << " moeda(s) de R$ 0.25" << endl;
	cout << _010 << " moeda(s) de R$ 0.10" << endl;
	cout << _005 << " moeda(s) de R$ 0.05" << endl;
	cout << _001 << " moeda(s) de R$ 0.01" << endl;
	
	return(0);
}
