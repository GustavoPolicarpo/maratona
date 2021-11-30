// Author: Gustavo Policarpo
// Name: Rabiola
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1876

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
	string in;
	while(cin >> in){
		int ans=0, x=0, aux=0;
		rep(i, 0, in.size()){
			if(in[i]=='x'){
				if(x) aux/=2;
				ans=max(ans, aux);
				aux=0, x=1;
				continue;
			}
			aux++;
		}
		if(!x) ans=aux;
		if(x){
			int i=in.size()-1; aux=0;
			while(in[i]!='x'){
				aux++, i--;
			}
			ans=max(ans, aux);
		}
		cout << ans << endl;
	}

return 0;
}
