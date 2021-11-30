// Author: Gustavo Policarpo
// Name: Friendly Int Parser
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1287

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

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < int, ii > iii;

void scanint(ll &x)
{
    register ll ccc = gc();
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
	string in;
	while(getline(cin, in)){
		ll num=-1; int fim=in.size();
		rep(i, 0, fim){
			if(isdigit(in[i])){
				if(num==-1) num=0;
				num*=10;
				num+=in[i]-'0';
			}
			else if(in[i]=='o' || in[i]=='O'){
				if(num==-1) num=0;
				num*=10;
				num+=0;
			}
			else if(in[i]=='l'){
				if(num==-1) num=0;
				num*=10;
				num+=1;
			}
			else if(in[i]!=',' && in[i]!=' '){
				num=-1;
				break;
			}
			if(num>2147483647){
				num=-1; 
				break;
			}
		}
		if(num==-1) puts("error");
		else printf("%lld\n", num);
	}
	
return 0;

}
