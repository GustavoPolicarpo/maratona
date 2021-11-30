// Author: Gustavo Policarpo
// Name: Bakugan
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1419

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
	int R;
	while(scanf("%d", &R) and R){
		int M[R], L[R], TM=0, TL=0;
		
		rep(i, 0, R) scanf("%d", &M[i]), TM+=M[i];
		rep(i, 0, R) scanf("%d", &L[i]), TL+=L[i];
		
		bool m=false, l=false;
		rep(i, 1, R-1){
			if(M[i]==M[i-1] && M[i]==M[i+1])
				m=true;
			if(L[i]==L[i-1] && L[i]==L[i+1])
				l=true;
			if(m && !l){ TM+=30; break;	} 
			if(l && !m){ TL+=30; break; }				
		}
		if(TM>TL) printf("M\n");
		else if(TL>TM) printf("L\n");
		else printf("T\n");
	}
					
return 0;
}
