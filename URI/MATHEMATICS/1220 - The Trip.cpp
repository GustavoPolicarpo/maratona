// Author: Gustavo Policarpo
// Name: The Trip
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1220

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
#define error 1e-2

typedef long long int ll;
typedef unsigned long long int ull;

//typedef pair < int, ii > iii;

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

int main()
{
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
	int N;
	while(scanf("%d", &N) and N){
		double total=0, out1=0, out2=0, aux; vector <double> in;
		rep(i, 0, N){
			scanf("%lf", &aux); 
			in.pb(aux), total+=aux;
		}
		total/=N;
		rep(i, 0, N){
			if(in[i]<total) out1+=(long)((total-in[i])*100.0)/100.0;
			else out2+=(long)((in[i]-total)*100.0)/100.0;
		}		
		double out=max(out1, out2);
		printf("$%.2lf\n", out);
	}

return 0;
}
