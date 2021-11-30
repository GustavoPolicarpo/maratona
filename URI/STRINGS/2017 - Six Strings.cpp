// Author: Gustavo Policarpo
// Name: Six Strings
// Level: 5
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2017

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



int main()
{
	char m[100001], in[100001];
	scanf("%s", &m);
	int k; cin >> k;
	int tm=strlen(m);
	int tin, ind=-1, val=INF, aux;
	rep(i, 0, 5){
		scanf("%s", &in);
		aux=0;
		rep(j, 0, tm){
			if(in[j]!=m[j]){
				aux++;
			}	
		}
		if(aux<val){
			ind=i+1, val=aux;
		}
	}
	
	if(ind==-1) printf("-1\n");
	else printf("%d\n%d\n", ind, val);	
	
return 0;
}
