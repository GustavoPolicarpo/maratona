// Author: Gustavo Policarpo
// Name: Hotel Rewards
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2351

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
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


int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, k; cin >> n >> k;
	int v[n]; rep(i, 0, n) scanf("%d", &v[i]);
	
	int sum=0, cnt=0;
	rep(i, 0, min(n, k)) sum+=v[i]; 
	
	priority_queue <int> pq;
	if(k<n) pq.push(-v[k]); cnt=1;
	
	rep(i, k+1, n){
		//cout << i << '\n';
		if((i+1)%(k+1)==0){
			pq.push(-v[i]);
			cnt++;
			continue;
		}
		if(-pq.top() < v[i]){
			sum+=-pq.top();
			pq.pop();
			pq.push(-v[i]);
		}else
			sum+=v[i];
	}
	
	printf("%d\n", sum);
	
	return 0;
	
}
