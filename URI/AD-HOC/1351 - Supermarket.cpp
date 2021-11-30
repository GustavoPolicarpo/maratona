// Author: Gustavo Policarpo
// Name: Supermarket
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1351

#define gc getchar_unlocked
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

#define INF 1e13
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, double > ii;
typedef pair < double, int > iii;


int N, M, n[101];
double pd[101][100001];
ii m[100001];

double solve(int i, int j){
	if(i==N) return 0.0;
	if(j==M) return INF;
	if(pd[i][j]>0.0) return pd[i][j];
	double ret=solve(i, j+1);
	if(m[j].F==n[i]){
		ret=min(ret, solve(i+1, j+1)+m[j].S);
	}
	return pd[i][j]=ret;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d %d", &N, &M) and N+M){
    	
    	rep(i, 0, N){
    		scanf("%d", &n[i]);
    		rep(j, 0, M+1)
    			pd[i][j]=-1;
		}
		
    	rep(i, 0, M){
    		scanf("%d %lf", &m[i].F, &m[i].S);
		}
			
		double out=solve(0, 0);
		if(out>=INF) printf("Impossible\n");
		else printf("%.2lf\n", out);
	}
    
    
return 0;
}


