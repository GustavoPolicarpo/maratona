// Author: Gustavo Policarpo
// Name: Engine Failure
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2167

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

int N, n[101];
int main()
{
    scanf("%d", &N);
    rep(i, 0, N){
    	scanf("%d", &n[i]);
	}
	int out=0;
	rep(i, 1, N)
		if(n[i]<n[i-1]){
			out=i+1;
			break;
		}
	cout << out << endl;

    
return 0;
}

