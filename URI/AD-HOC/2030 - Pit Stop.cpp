// Author: Gustavo Policarpo
// Name: Pit Stop
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2030

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define MAXV 100001
#define mod 1000000007
#define INF 0x3f3f3f3f
#define all(c) c.begin(), c.end()

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

int t1, t2, A, V, R;
ii pd[101][101][101];

ii solve(int r, int v, int t){
	//cout << r << '\n';
	if(r==0) return mp(0,0);
	
	if(pd[r][v][t].F!=-1) return pd[r][v][t];
	
	ii ret=mp(INF, INF);
	
	if(v<=0){
		ii a=solve(r-1, V, t+1);
		a.F+=t2+A, a.S++;
		
		ii b=solve(r-1, 0, t);
		b.F+=t2, b.S+=0;
		
		ret=min(a, b);
	}
	
	else{
		ii a=solve(r-1, V, t+1);
		a.F+=t1+A, a.S++;
		
		ii b=solve(r-1, v-1, t);
		b.F+=t1, b.S+=0;
		
		ret=min(a, b);
	}
	
	return pd[r][v][t]=ret;
	
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
	int T; cin >> T;
	rep(z, 0, T){
		scanf("%d %d %d %d %d", &t1, &t2, &A, &V, &R);
		printf("Teste #%d\n", z+1);
		rep(i, 0, R+1)
		rep(j, 0, V+1)
		rep(k, 0, R+1)
			pd[i][j][k]=mp(-1, -1);
		
		ii out=solve(R, V, 0);
		printf("%lld %d\n\n", out.F, out.S);
	}
	
	return 0;
	
}
