// Author: Gustavo Policarpo
// Name: Energy Planning
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1540

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
//

int main()
{
//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	while(T--){
		double A, B, C, D;
		scanf("%lf %lf %lf %lf", &A, &B, &C, &D);
		double taxa=(D-B)/(C-A);
		ll inteira=taxa; taxa*=100;
		ll decimal=taxa; decimal%=100;
		printf("%lld,%.2lld\n", inteira, decimal);
	}

return 0;
}


