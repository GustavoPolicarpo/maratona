// Author: Gustavo Policarpo
// Name: Approximate Number of Primes
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2159

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
typedef pair < double, int > iii;

int main()
{
    int N; cin >> N;
    double min=N/log(N);
    double max=1.25506*N/log(N);
    printf("%.1lf %.1lf\n", min, max);

return 0;
}

