// Author: Gustavo Policarpo
// Name: Balé
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2400

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

const int MAXV = 100010;
int in[MAXV], BIT[MAXV], n;

void update(int x, int v){ 
    while(x <= n){ 
        BIT[x] += v; 
        x += x&-x; 
    } 
} 
  
int query(int x){ 
    int ans = 0; 
    while(x > 0){ 
        ans += BIT[x]; 
        x -= x&-x; 
    } 
    return ans; 
}


int main()
{
	scanint(n);
	
	rep(i, 0, n) scanint(in[i]);
	
	
	int ans=0;
	for(int i=n-1; i>=0; i--){
		ans += query(in[i]);
		update(in[i], 1);
	}
	
	printf("%d\n", ans);
	
	return 0;
		
}
