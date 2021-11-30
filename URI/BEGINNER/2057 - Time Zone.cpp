// Author: Gustavo Policarpo
// Name: Time Zone
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2057

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;


int main()
{
	int S, T, F;
	cin >> S >> T >> F;
	int aux=S+T+F;
	if(aux>=24)
		aux-=24;
	else if(aux<0)
		aux+=24;
	cout << aux << endl;

return (0);
}

