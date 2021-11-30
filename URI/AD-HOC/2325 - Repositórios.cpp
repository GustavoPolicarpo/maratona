// Author: Gustavo Policarpo
// Name: Repositórios
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2325

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


int main()
{
	int N, M, a, b; cin >> N >> M;
	map <int, int> n, m, out;
	map<int, int>::iterator it;
	
	rep(i, 0, N){
		scanf("%d %d", &a, &b);
		n[a]=b;
	}
	
	rep(i, 0, M){
		scanf("%d %d", &a, &b);
		if(!m.count(a) || m[a]<b)
			m[a]=b;
	}
	
	for(it=n.begin(); it!=n.end(); it++){
		if(m[it->first] > it->second)
			out[it->first]=m[it->first];
		m[it->first]=0;	
	}
	
	
	
	for(it=m.begin(); it!=m.end(); it++){
		if(it->second)
			out[it->first]=it->second;
	}
	
	for(it=out.begin(); it!=out.end(); it++)
		printf("%d %d\n", it->first, it->second); 
	

	return 0;
	
}
