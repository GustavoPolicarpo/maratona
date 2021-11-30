// Author: Gustavo Policarpo
// Name: Elementary, my Dear Watson!
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1382

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




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; scanint(T);
	while(T--){
		int N; scanint(N); int n[N], cnt=0;
		rep(i, 1, N+1) scanint(n[i]);
		
		rep(i, 1, N+1){
			while(n[i]!=i){
				swap(n[i], n[n[i]]);
				cnt++;
			}
		}
		
		//rep(i, 1, N+1) cout << n[i] << ' ';
		//				cout << '\n';
		
		printf("%d\n", cnt);
	}

	return 0;

}



