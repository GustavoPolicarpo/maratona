// Author: Gustavo Policarpo
// Name: Dengue
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2088

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
//freopen("out.txt", "w", stdout);
int n; 
double grafo[18][18], memo[18][1 << 18];

double tsp(int pos, int bitmask) 
{
	if (bitmask == (1 << (n )) - 1) return grafo[pos][0]; 
	if (memo[pos][bitmask] != -1) return memo[pos][bitmask];
	
	double ans = INF;
	for (int nxt = 0; nxt <= n; nxt++) 
		if (nxt != pos && !(bitmask & (1 << nxt))) 
			ans = min(ans, grafo[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
	return memo[pos][bitmask] = ans;
}

struct pt{
	int x, y;
};

double dst(pt a, pt b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
	while(scanf("%d", &n) and n){
		int last=1<<n+1;
		rep(i, 0, n+1){
			rep(j, 0, last)
				memo[i][j]=-1;
			rep(k, 0, n+2)
				grafo[i][k]=grafo[k][i]=INF;
			grafo[i][i]=0;
		}
			
		n+=1;
		pt array[20];
		rep(i, 0, n)
			scanf("%d %d", &array[i].x, &array[i].y);
		
		rep(i, 0, n)
			rep(j, i+1, n)
				grafo[i][j]=grafo[j][i]=dst(array[i], array[j]);//, cout << grafo[i][j] << endl;
				
		double out=tsp(0, 0);
		printf("%.2lf\n", out);	
	}
	
return 0;
}


