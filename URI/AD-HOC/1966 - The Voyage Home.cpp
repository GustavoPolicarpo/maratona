// Author: Gustavo Policarpo
// Name: The Voyage Home
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1966

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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;


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

struct qq{
	int v, c;
	double r;
};

qq n[100010];

bool cmp(qq a, qq b){
	return a.r>b.r;
}
int main ()
{
	int N, B; 
	ll b=0;
	scanf("%d %d", &N, &B);
	
	rep(i, 0, N) scanf("%d", &n[i].v);
	rep(i, 0, N){
		scanf("%d", &n[i].c);
		if(n[i].c==0) {
			n[i].r=INF;
		}
		else n[i].r = (double) n[i].v/n[i].c;
	}
	
	sort(n, n+N, cmp);
		
	rep(i, 0, N){
		if(n[i].r==INF){
			//cout << n[i].v << endl;
			b+=n[i].v;
			//cout << "  " <<  b << endl;
			continue;
		}
		int aux=min(n[i].c, B);
		//cout << aux*n[i].r << endl;
		b+=(aux*n[i].r+error);
		//cout << "  " <<  b << endl;
		B-=aux;
	}
	//cout << b << endl;
	ll out=(-1 + sqrt(1 + ll(8)*b))/2;
	
	cout << out << endl;
  
  return 0;
}

