// Author: Gustavo Policarpo
// Name: Chocolate Factory
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1573

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
	int A, B, C;
	while(scanf("%d %d %d", &A, &B, &C) and A+B+C){
		double cubo=pow(A*B*C, 1.0/3.0);
		cout << trunc(cubo) << endl;
	}
	
return 0;
}
