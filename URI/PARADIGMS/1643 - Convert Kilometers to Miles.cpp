// Author: Gustavo Policarpo
// Name: Convert Kilometers to Miles
// Level: 3
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1643

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

#define INF 0x3F3F3F3F3
#define MAXV 100001

#define error 1e-9

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


int main()
{
	int fib[42];
	fib[0]=1, fib[1]=2;
	rep(i, 2, 36){
		fib[i]=fib[i-1]+fib[i-2];
	}

	int T, in, j, ans; cin >> T;
	while(T--){
		scanf("%d", &in); j=32, ans=0;
		while(in<fib[j]) j--;
		vector <int> bin;
		while(in){
			//cout << in << endl;
			if(in>=fib[j]){
				in-=fib[j];
				bin.pb(1);
			}
			else bin.pb(0);
			j--;
		}	
		while(j>=0) bin.pb(0), j--;
		reverse(bin.begin(), bin.end());
		
		rep(i, 1, bin.size()){
			ans+=fib[i-1]*bin[i];
		}
		
		cout << ans << endl;
	}
	
	return 0;	
}
