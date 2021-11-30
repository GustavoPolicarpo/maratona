// Author: Gustavo Policarpo
// Name: Where Are My Keys
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1800

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
	int N, E, aux;
	scanf("%d %d", &N, &E);
	set <int> jafoi;
	rep(i, 0, E){
		scanf("%d", &aux);
		jafoi.insert(aux);
	}
	rep(i, 0, N){
		scanf("%d", &aux);
		if(jafoi.count(aux))
			printf("0\n");
		else
			printf("1\n"), jafoi.insert(aux);
	}


return 0;
}
