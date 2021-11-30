// Author: Gustavo Policarpo
// Name: Removing Letters
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1556

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

set <string> has;
set <string>:: iterator it;

void solve(char s[], int t){
	if(t==0) return;
	has.insert(s);
	
	rep(i, 0, t){
		char aux[1001]; int p=0;
		rep(j, 0, t){
			if(j==i) continue;
			aux[p++]=s[j];
		}	aux[p]='\0';
		if(!has.count(aux))
			solve(aux, t-1);
	}
}
int main()
{
	char s[1001];
	
	while(scanf("%s", s)!=EOF){
		has.clear();
		
		int tam=strlen(s);
		
		solve(s, tam);
			
		for(it=has.begin(); it!=has.end(); it++)
			cout << *it << '\n';
		cout << '\n';
	}
	
	return 0;
	
}



