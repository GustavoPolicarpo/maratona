// Author: Gustavo Policarpo
// Name: SSN 2
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1786

#define gc getchar_unlocked
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



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string in;
	while(cin >> in){
		int f=0, s=0, j=0;
		for(int i=1; i<=9; i++){
			f+=(in[j++]-'0')*i;
		}
		j=0;
		for(int i=9; i>=1; i--){
			s+=(in[j++]-'0')*i;
		}
		f%=11; if(f==10) f=0;
		s%=11; if(s==10) s=0;
		string a, b, c;
		rep(i, 0, 3) cout << in[i];
		cout << ".";
		rep(i, 3, 6) cout << in[i];
		cout << ".";
		rep(i, 6, 9) cout << in[i];
		cout << "-";
		cout << f << s << '\n';
	}
						
return 0;
}
