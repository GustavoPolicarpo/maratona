// Author: Gustavo Policarpo
// Name: Polynomial Derivative
// Level: 3
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2154

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
	int T; 
	while(scanf("%d", &T)!=EOF){
		bool mark=false;
		int a, b; char nada;
		rep(i, 0, T){
			if(i>0) scanf(" %c", &nada);
			scanf("%d%c%d", &a, &nada, &b);
			if(i>0) printf(" + ");
			if(b==2) printf("%dx", a*b);
			else printf("%dx%d", a*b, b-1);
		}
		printf("\n");
	}

return 0;
}
