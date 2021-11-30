// Author: Gustavo Policarpo
// Name: Travel to Mars in Primo S...
// Level: 2
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2180

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
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

bool isprime(int n){

	rep(i, 2, sqrt(n)+1){
		if(n%i==0) return false;
	}
	return true;	
}

int main()
{
	int P; cin >> P; int cnt=0, aux=P; ll out=0;
	while(cnt<10){
		if(isprime(aux)){
			cnt++, out+=aux;
			//cout << aux << endl;
		}
		aux++;
	}
	int num=60000000;
	printf("%lld km/h\n", out);
	int h=num/out, d=h/24;
	printf("%d h / %d d\n", h, d);
		
return 0;
}
