// Author: Gustavo Policarpo
// Name: Quid Est Veritas? Est Vir...
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1580

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
typedef pair < int, string > ii;
typedef pair < double, int > iii;

#define mod 1000000007
ll fastexp(ll a,int b)
{
	ll x;

	if(b==0) return 1;	
	if(b==1) return a;

	if(b%2==0){
		x = fastexp(a,b/2)%mod;
		return (x*x)%mod;
	}
	else{
		return (a*fastexp(a,b-1))%mod;
	}
}

ll inverso(ll a)
{
  return fastexp(a,mod-2);
}

int vet[30];
ll fat[1001];
char in[1001];
int main()
{
	fat[1]=1;
	for(ll i=2; i<1001; i++) fat[i]=(fat[i-1]*i)%mod;
	while(scanf("%s", &in) !=EOF){
		memset(vet, 0, sizeof vet);
		int total=strlen(in);
		rep(i, 0, total)
			vet[in[i]-'A']++;
		
		ll num=fat[total];
		rep(i, 0, 30){
			ll den=0;
			if(vet[i]!=0){
				den=inverso(fat[vet[i]]);
				num=(num*den)%mod;
			}		
		}
		printf("%lld\n", num);
	
	}
	
return 0;	
}
