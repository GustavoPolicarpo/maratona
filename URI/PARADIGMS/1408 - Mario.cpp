// Author: Gustavo Policarpo
// Name: Mario
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1408

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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

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

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, L, aux;
	while(1){
		
		scanint(N), scanint(L);
		if(!(N+L)) break;
		
		int n[L];
		rep(i, 0, L) scanint(n[i]);
			
		int ans, i=0, j;
		j=lower_bound(n, n+L, n[0]+N)-n;
		ans=N-j;
		
		while(j<L){
			
			if(n[j]-n[i]>=N-1){
				
				if(n[j]-n[i]==N-1){
					if(N-j+i-1<ans) ans=N-j+i-1;
					i++;
				}		
				else if(N-j+i<ans) ans=N-j+i;
					
				while(n[j]-n[i]>=N) i++;
			}
			
			else j++;
		}
		
		printf("%d\n", ans);
		
	}
	return 0;
}
