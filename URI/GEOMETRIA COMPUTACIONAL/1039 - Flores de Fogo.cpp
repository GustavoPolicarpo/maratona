// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Flores de Fogo
// Nível: 2
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1039

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
typedef pair < int, ii > iii;



int main()
{
	double R1, X1, Y1, R2, X2, Y2, r;
	while(cin>>R1>>X1>>Y1>>R2>>X2>>Y2){
		r=sqrt(pow((X1-X2),2)+pow((Y1-Y2),2));
		
		if(r+R2<=R1) cout << "RICO";
		else cout << "MORTO";
		cout << endl;
	}	
return 0;
}
