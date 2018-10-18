// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Subsequências
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1507

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


int main()
{
	char S[100001], s[101];
	int T, Q, a, b; cin >> T;
	while(T--){
		scanf("%s", &S); a=strlen(S);
		scanf("%d", &Q);
		while(Q--){
			scanf("%s", &s);
			b=strlen(s);
			int i=0, j=0; bool yep=false;
			for(int i=0; i<a; i++){
				if(S[i]==s[j]){
					j++;
					if(j==b){
						yep=true;
						break;
					}
				}
			}
			if(yep) printf("Yes");
			else printf("No");
			printf("\n");
		}
	}
    

    
return 0;
}

