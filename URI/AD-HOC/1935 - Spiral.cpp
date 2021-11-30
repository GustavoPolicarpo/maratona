// Author: Gustavo Policarpo
// Name: Spiral
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1935

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



ll pa(ll n){
	return n*(0+(n-1)*2)/2;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	/*
	1  2  3	 4 	5
	16 17 18 19	6
	15 24 25 20	7
	14 23 22 21	8
	13 12 11 10 9
	
1 	2 	3 	4 	5 	6
20	21	22	23	24	7
19	32	33	34	25	8
18	31	36	35	26	9
17	30	29	28	27	10
16	15	14	13	12	11
*/
	
// atual + N*4-4 + (N-2)*4-4 + (N-4)*4-4...
   //atual + -4*n + 4*(N*n-pa(0, n));

	ll N, B, x=1, y=1;
	scanf("%lld %lld", &N, &B);
	ll atual=1, go=1LL<<30;
	
	while(go){
		if(go*2 >= N){
			go/=2;
			continue;
		}
		if(atual + ll(4)*(N*go-pa(go)) - ll(4)*go <= B)
		x+=go, y+=go, atual=atual+ll(4)*(N*go-pa(go)) - ll(4)*go, N-=go*2; //cout << N << " " << atual << '\n';
		else go/=2;
	}
	
	
	if(atual + 3*N-3 == B){
		x+=N-1;
		printf("%lld %lld\n", x, y);
		return 0;
	}
	if(atual + 2*N-2 == B){
		x+=N-1, y+=N-1;
		printf("%lld %lld\n", x, y);
		return 0;
	}
	if(atual + 1*N-1 == B){
		y+=N-1;
		printf("%lld %lld\n", x, y);
		return 0;
	}
	if(atual + 0*N-0 == B){
		printf("%lld %lld\n", x, y);
		return 0;
	}
	
	if(atual + 3*N-3 < B){
		ll aux = B - (atual + 3*N-3);
		x+=N-1 - aux;
		printf("%lld %lld\n", x, y);
		return 0;
	}
	
	if(atual + 2*N-2 < B){
		ll aux = B - (atual + 2*N-2);
		x+=N-1, y+=N-1 - aux;
		printf("%lld %lld\n", x, y);
		return 0;
	}
	
	if(atual + 1*N-1 < B){
		ll aux = B - (atual + 1*N-1);
		x+=aux, y+=N-1;
		printf("%lld %lld\n", x, y);
		return 0;
	}
	
	if(atual + 0*N-0 < B){
		ll aux = B - (atual + 0*N-0);
		y+=aux;
		printf("%lld %lld\n", x, y);
		return 0;
	}
	

	return 0;
	
}
