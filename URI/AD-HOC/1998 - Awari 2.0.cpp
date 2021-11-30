// Author: Gustavo Policarpo
// Name: Awari 2.0
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1998

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
	int N;
	while(scanf("%d", &N) and N!=-1){
		int n[N+1], p=0;
		rep(i, 1, N+1)
			scanf("%d", &n[i]);
		bool yep=true;
		for(int i=N; i>1; i--){
			if(n[i]==0 && p==0) continue;
			if((n[i]+p)%i!=0){
				yep=false;
				break;
			}
			else p+=(n[i]+p)/i;
		}
		if(yep) printf("S\n");
		else printf("N\n");
	}

return 0;
}
