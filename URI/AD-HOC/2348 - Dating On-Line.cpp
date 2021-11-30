// Author: Gustavo Policarpo
// Name: Dating On-Line
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2348

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
	int N, aux; cin >> N;
	vector <int> n, dq;
	
	rep(i, 0, N){
		scanint(aux);
		n.pb(aux);
	}
	
	sort(n.begin(), n.end());
	
	for(int i=0; i<N; i+=2) dq.pb(n[i]);
	for(int i=N-1 - (N&1); i>=0; i-=2) dq.pb(n[i]);
	//rep(i, 0, N) cout << dq[i] << " ";
	
	long double ans=0.0, ang=2.0*M_PI/N;
	rep(i, 0, N){
		long double a=dq[i], 
					b=dq[(i+1)%N], 
					c = sqrt(a*a + b*b - 2.0*a*b*cos(ang)),
					p=(a+b+c)/2.0,
					area=sqrt(p*(p-a)*(p-b)*(p-c));
		ans+=area;
	}
	
	cout << fixed << setprecision(3) << ans << '\n';


	return 0;
	
}
