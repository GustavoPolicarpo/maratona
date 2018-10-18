// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pepe, Já Tirei a Vela!
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2152

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int T, h, m, op; cin >> T; 
	while(T--){
		scanf("%d %d %d", &h, &m, &op);
		if(h<10) printf("0");
		printf("%d:", h);
		if(m<10) printf("0");
		printf("%d - ", m);
		if(op==0) printf("A porta fechou!\n");
		else printf("A porta abriu!\n");
	}


return 0;
}


