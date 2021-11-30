// Author: Gustavo Policarpo
// Name: Grades
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2469

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
	int N, aux, ans=0, nt=0; scanint(N);
	map <int, int> in;
	
	while(N--){
		scanint(aux);
		in[aux]++;
		if(in[aux] > ans) ans=in[aux], nt=aux;
		else if(in[aux] == ans && aux>nt) ans=in[aux], nt=aux;
	}
	
	printf("%d\n", nt);

	return 0;
	
}
