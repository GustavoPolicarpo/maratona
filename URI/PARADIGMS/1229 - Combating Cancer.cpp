// Author: Gustavo Policarpo
// Name: Combating Cancer
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1229

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



const int MAX = 10010;
int N;
vector <int> A[MAX], NA[MAX], B[MAX], NB[MAX];

bool comp(const vector <int> & a, const vector <int> & b){
	if(a.size()!=b.size()) return a.size()<b.size();
	rep(i, 0, a.size())
		if(a[i]!=b[i]) return a[i]<b[i];
	return false;
}

bool eq(const vector <int> & a, const vector <int> & b){
	if(a.size()!=b.size()) return false;
	rep(i, 0, a.size())
		if(a[i]!=b[i]) return false;
	return true;
}

bool treeIsomorphism(){
	memset(NA, 0, sizeof NA);
	memset(NB, 0, sizeof NB);
	
	rep(i, 1, N+1){
		rep(j, 0, A[i].size()) NA[i].pb( A[A[i][j]].size() );
		sort(NA[i].begin(), NA[i].end());
		
		rep(j, 0, B[i].size()) NB[i].pb( B[B[i][j]].size() );
		sort(NB[i].begin(), NB[i].end());
	}
	
	sort(NA + 1, NA + N + 1, comp);
	sort(NB + 1, NB + N + 1, comp);
	
	rep(i, 1, N+1){
		if(!eq(NA[i], NB[i]))
			return false;
	}
	
	return true;
	
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while(scanf("%d", &N) !=EOF){
		int u, v;
		
		rep(i, 1, N+1) A[i].clear(), B[i].clear();
		
		rep(i, 1, N){
			scanf("%d %d", &u, &v);
			A[u].pb(v);
			A[v].pb(u);
		}
		
		rep(i, 1, N){
			scanf("%d %d", &u, &v);
			B[u].pb(v);
			B[v].pb(u);
		}
		
		puts(treeIsomorphism() ? "S" : "N");
		
	}


	return 0;
	
}
