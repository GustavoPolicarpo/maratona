// Author: Gustavo Policarpo
// Name: Supermarket Line
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2065

//#define gc getchar_unlocked
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


/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

typedef pair < ll, int > ii;

int main()
{
	int N, M;
	
	scanf("%d %d", &N, &M);
	
	int n[N], m[M];
	rep(i, 0, N) scanf("%d", &n[i]);
	rep(i, 0, M) scanf("%d", &m[i]);

	priority_queue <ii> pq;
	rep(i, 0, N) pq.push(mp(-n[i]*m[i], -i));
	
	rep(i, N, M){
		ii aux=pq.top();
	//	cout << aux.F << " " << aux.S << endl;
		pq.push(mp(aux.F-n[-aux.S]*m[i], aux.S)); pq.pop();
	}
	
	while(pq.size()>1) pq.pop();
	
	printf("%lld\n", -pq.top().F);
	

return 0;

}
