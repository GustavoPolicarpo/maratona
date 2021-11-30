// Author: Gustavo Policarpo
// Name: Threebonacci Sequence
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1739

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


ll n[65];
ll fib[1000];
int main(){
	fib[0]=1, fib[1]=2;
	int cnt=0, i=2;
	while(cnt<=60){
		fib[i]=fib[i-1]+fib[i-2];
		ll aux=fib[i];
		if(aux%3==0){
			n[cnt++]=fib[i];
		}
		else{
			while(aux){
				if(aux%10==3){
					n[cnt++]=fib[i];
					break;
				}
				aux/=10;
			}
		}
		i++;
	}
	
	int N;
	while(scanf("%d", &N) !=EOF){
		printf("%lld\n", n[N-1]);
	}
	return 0;	
}

