// Author: Gustavo Policarpo
// Name: Not One More Canadian Game!
// Level: 5
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2132

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


char in[75]; int z=1;
int main()
{
	while(scanf("%s", &in) !=EOF){
		ll out=0; int tam=strlen(in);
		rep(i, 0, tam){
			if(in[i]=='b'){
				out+=pow(2, tam-i-1);
			}
		}
		printf("Palavra %d\n", z++);
		printf("%lld\n\n", out);
	}
		
return 0;
}


