// Author: Gustavo Policarpo
// Name: Counting Substhreengs
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1745

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



char s[1000010];

int main()
{
	scanf("%s", s); int fim=strlen(s);
	ll ans=0, aux=0; int cnt[3]; cnt[1]=cnt[2]=0, cnt[0]=1;
	
	rep(i, 0, fim){
		if(!isdigit(s[i])) aux=0, cnt[1]=cnt[2]=0, cnt[0]=1;
		else{
			aux+=s[i]-'0', aux%=3;
			ans+=cnt[aux], cnt[aux]++;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;
	
}
