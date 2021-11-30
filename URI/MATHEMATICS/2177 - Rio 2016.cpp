// Author: Gustavo Policarpo
// Name: Rio 2016
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2177

//#define gc getchar_unlocked
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

int main()
{
	int X, x, Y, y, N, n; cin >> X >> Y >> N; bool mark=false;
	rep(i, 0, N) {
		scanf("%d %d %d", &x, &y, &n);
		double aux=sqrt((X-x)*(X-x)+(Y-y)*(Y-y));
		if(aux<n){
			if(mark) printf(" ");
			else mark=true;
			printf("%d", i+1);
		}	
	}	
	if(!mark) printf("-1");
	printf("\n");
	
return 0;
}



