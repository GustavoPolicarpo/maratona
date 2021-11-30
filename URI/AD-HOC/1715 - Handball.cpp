// Author: Gustavo Policarpo
// Name: Handball
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1715

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
	int N, M, aux, cont=0; cin >> N >> M;

	rep(i, 0, N){
		bool yep=true;
		rep(j, 0, M){
			scanf("%d", &aux);
			if(aux==0) yep=false;
		}
		if(yep) cont++;
	}
	printf("%d\n", cont);
		
			
return 0;
}
