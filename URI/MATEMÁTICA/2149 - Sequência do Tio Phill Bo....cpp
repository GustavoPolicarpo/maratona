// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência do Tio Phill Bo...
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2149

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
	ull vet[20];
	vet[0]=0, vet[1]=1;
	rep(i, 2, 18){
		if(i%2==0){
			vet[i]=vet[i-1]+vet[i-2];
		}
		else
			vet[i]=vet[i-1]*vet[i-2];
	}
	//rep(i, 0, 18)
		//cout << vet[i] << " ";
	int in; 
	while(scanf("%d", &in)!=EOF){
		cout << vet[in-1] << endl;
	}


return 0;
}


