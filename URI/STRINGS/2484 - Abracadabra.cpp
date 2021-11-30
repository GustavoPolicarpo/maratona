// Author: Gustavo Policarpo
// Name: Abracadabra
// Level: 4
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2484

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int main()
{
	
	char s[101];
	
	while(scanf("%s", s)!=EOF){
		int tam=strlen(s);
		int esp=0;
		while(tam){
			rep(i, 0, esp) printf(" ");
			rep(i, 0, tam){
				if(i) printf(" ");
				printf("%c", s[i]);
			}
			esp++, tam--;
			printf("\n");
		}
		printf("\n");
	}
	
	
	return 0;
	
}
