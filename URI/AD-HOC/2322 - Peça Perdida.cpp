// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Peça Perdida
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2322

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N, aux;	cin >> N;
	int n[N+1];
	memset(n, 0, sizeof n);
	
	rep(i, 0, N-1){
		scanf("%d", &aux);
		n[aux]=1;
	}
	
	rep(i, 1, N+1){
		if(!n[i]){
			printf("%d\n", i);
			return 0;
		}
	
	}
	
	return 0;
	
}
