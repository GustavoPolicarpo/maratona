// Author: Gustavo Policarpo
// Name: Odd, Even or Cheating
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2059

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
		
	int p, j1, j2, r, a;
	cin >> p >> j1 >> j2 >> r >> a;
	int soma=j1+j2;
	if(r==1&&a==0)
		cout << "Jogador 1 ganha!";
	else if(r==0&&a==1)
		cout << "Jogador 1 ganha!";
	else if(r==1&&a==1)
		cout << "Jogador 2 ganha!";
	else{
		if(p==1&&soma%2==0)
			cout << "Jogador 1 ganha!";
		else if(p==0&&soma%2==1)
			cout << "Jogador 1 ganha!";
		else
			cout << "Jogador 2 ganha!";
	}
	cout << endl;
return (0);
}
