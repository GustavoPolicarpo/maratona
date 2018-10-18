// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Escada Rolante
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1793

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define error 1e-4

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < char, int > ii;
typedef pair < double, int > iii;

int main()
{	
	int N, t[100], out;
	while(scanf("%d", &N) && N){
		out=10;
		rep(i, 0, N)
			scanf("%d", &t[i]);
		rep(i, 0, N-1){
			if(t[i+1]-t[i]<10) out+=t[i+1]-t[i];
			else out+=10;
		}
		cout << out << endl;	
	}
	
return 0;
}
