// Author: Gustavo Policarpo
// Name: Pomekon Tournament
// Level: 5
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2224

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

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int T, N;
double pd[18][10][1<<18 + 1], grafo[18][18];
struct ponto{
	int x, y;
}; ponto n[20];
double dst(ponto a, ponto b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double solve(int i, int c, int mask){

	if(i>N || c<0) return INF;
	if(mask==(1<<N)-1){
		if(c==0) return 0.0;
		else return INF;
	}
	if(pd[i][c][mask]>0) return pd[i][c][mask];
	
	double ret=INF;
	if(mask&(1<<i)) ret=min(ret, solve(i+1, c, mask));
	ret=min(ret, solve(i+1, c-1, mask|(1<<i)));
	
	if(!(mask&(1<<(i+1)))){
		int aux=mask|(1<<i);
		aux|=(1<<(i+1));
		ret=min(ret, solve(i+2, c-1, aux)+grafo[i][i+1]);
	}
		
	rep(j, i+2, N){
		if(mask&(1<<j)) continue;
		int aux=mask|(1<<i);
		aux|=(1<<(j));
		ret=min(ret, solve(i+1, c-1, aux)+grafo[i][j]);
	}
	
	return pd[i][c][mask]=ret;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    cin >> T;
    while(T--){
    	scanf("%d", &N); int c=N/2+(N%2==1);
    	rep(i, 0, N){
    		scanf("%d %d", &n[i].x, &n[i].y);
    		rep(j, 0, c+1)
    		rep(k, 0, 1<<N + 1) pd[i][j][k]=-1.0;
		}
		rep(i, 0, N)
		rep(j, i+1, N) grafo[i][j]=grafo[j][i]=dst(n[i], n[j]);
		
		double out=solve(1, c-1, (1<<0));
		if(N>1)
			out=min(out, solve(2, c-1, (1<<0)|(1<<1))+grafo[0][1]);
		rep(i, 2, N){
			out=min(out, solve(1, c-1, (1<<0)|(1<<i))+grafo[0][i]);
		} 
		printf("%.2lf\n", out);
	}
       
return 0;
}

