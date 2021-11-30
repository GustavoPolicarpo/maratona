// Author: Gustavo Policarpo
// Name: Start Grid
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1228

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;




int main()
{
	int N;
	while(scanf("%d", &N) != EOF){
		int L[N], C[N];
		rep(i, 0, N)
			scanf("%d", &L[i]);
		rep(i, 0, N)
			scanf("%d", &C[i]);	
		int P=0;
		rep(i, 0, N){
			reo(j, N-1, i)
				if(C[j]==L[i])
					swap(C[j], C[j-1]), P++;								
		}
		cout << P << endl;			
	}
	
return 0;
}
