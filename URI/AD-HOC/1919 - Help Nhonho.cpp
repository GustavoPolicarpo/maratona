// Author: Gustavo Policarpo
// Name: Help Nhonho
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1919

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;
 
struct ind{
	int a, b, c, d, e;
};
 
int main()
{
	int T; cin >> T;
	while(T--){
		int K; scanf("%d", &K);
		if(K<2666640){
			printf("impossivel\n\n");
			continue;
		}
		vector <ind> out; ind pus;
		rep(a, 0, 10)
		rep(b, a+1, 10)
		rep(c, b+1, 10)
		rep(d, c+1, 10)
		rep(e, d+1, 10){
		int aux=a+b+c+d+e;
		ll sum=24*10000*aux+
				24*1000*aux+
				 24*100*aux+
				  24*10*aux+
				   24*1*aux;
			if(sum==K){
				pus.a=a, pus.b=b, pus.c=c,
				pus.d=d, pus.e=e;
				out.pb(pus);
			}
		}
		if(out.size()==0){
			printf("impossivel\n\n");
			continue;
		}
		rep(i, 0, out.size()){
			printf("{%d,%d,%d,%d,%d}\n",out[i].a,out[i].b,out[i].c,out[i].d,out[i].e);
		}
		printf("\n");
	}
		
return 0;
} 
