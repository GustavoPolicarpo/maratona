// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Lajotas Hexagonais
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1393

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N;

int main()
{
	cin >> N;
	while(N!=0)
	{
		switch(N)
		{
			case 1: cout << 1 << endl; break;
			case 2: cout << 2 << endl; break;
			case 3: cout << 3 << endl; break;
			case 4: cout << 5 << endl; break;
			case 5: cout << 8 << endl; break;
			case 6: cout << 13 << endl; break;
			case 7: cout << 21 << endl; break;
			case 8: cout << 34 << endl; break;
			case 9: cout << 55 << endl; break;
			case 10: cout << 89 << endl; break;
			case 11: cout << 144 << endl; break;
			case 12: cout << 233 << endl; break;
			case 13: cout << 377 << endl; break;
			case 14: cout << 610 << endl; break;
			case 15: cout << 987 << endl; break;
			case 16: cout << 1597 << endl; break;
			case 17: cout << 2584 << endl; break;
			case 18: cout << 4181 << endl; break;
			case 19: cout << 6765 << endl; break;
			case 20: cout << 10946 << endl; break;
			case 21: cout << 17711 << endl; break;
			case 22: cout << 28657 << endl; break;
			case 23: cout << 46368 << endl; break;
			case 24: cout << 75025 << endl; break;
			case 25: cout << 121393 << endl; break;
			case 26: cout << 196418 << endl; break;
			case 27: cout << 317811 << endl; break;
			case 28: cout << 514229 << endl; break;
			case 29: cout << 832040 << endl; break;
			case 30: cout << 1346269 << endl; break;
			case 31: cout << 2178309 << endl; break;
			case 32: cout << 3524578 << endl; break;
			case 33: cout << 5702887 << endl; break;
			case 34: cout << 9227465 << endl; break;
			case 35: cout << 14930352 << endl; break;
			case 36: cout << 24157817 << endl; break;
			case 37: cout << 39088169 << endl; break;
			case 38: cout << 63245986 << endl; break;
			case 39: cout << 102334155 << endl; break;
			case 40: cout << 165580141 << endl; break;
		}
		cin >> N;
	}
}
