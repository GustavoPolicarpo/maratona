// Author: Gustavo Policarpo
// Name: Two Bills
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2140

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
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int n[6];
	n[0]=2, n[1]=5, n[2]=10, n[3]=20, n[4]=50, n[5]=100;
	int N, M, T;
	while(scanf("%d %d", &N, &M) and N+M){
		T=M-N;
		bool yep=false;
		rep(i, 0, 5)
			rep(j, i+1, 6)
				if(n[i]+n[j]==T){
					yep=true;
					break;
				}
		if(yep) printf("possible\n");
		else printf("impossible\n");
	}
	
	
			
return 0;
}
