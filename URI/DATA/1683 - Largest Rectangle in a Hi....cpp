// Author: Gustavo Policarpo
// Name: Largest Rectangle in a Hi...
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1683

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, n[100010];


ll max_area(){
	
	stack <ll> s;
	ll ans=0, atual; int i=0, tp;
	
	while(i<N){
		
		if(s.empty() || n[s.top()]<=n[i]) s.push(i++);
		else{
			tp=s.top(), s.pop();
			atual=n[tp]*(s.empty() ? i : i - s.top() - 1);
			
			if(ans<atual) ans=atual;
		}
		
	}
	
	while (!s.empty()){
		
        tp = s.top(), s.pop();
        atual = n[tp] * (s.empty() ? i : i - s.top() - 1);
 
        if(ans<atual) ans=atual;
            
    }
    
    return ans;
    
}
int main()
{
	while(1){
		scanint(N);
		if(!N) break;
		rep(i, 0, N) scanint(n[i]);
		
		printf("%lld\n", max_area());
	}

	return 0;
}



