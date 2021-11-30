// Author: Gustavo Policarpo
// Name: Mini-Poker
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2298

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


int ans(int *n){
	
	bool yep=true;
	rep(i, 1, 5) if(n[i]!=n[i-1]+1)	{ yep=false; break; }
	if(yep) return n[0]+200;
	
	if(n[0]==n[1]&&n[1]==n[2]&&n[2]==n[3]) return n[0]+180; 
	if(n[1]==n[2]&&n[2]==n[3]&&n[3]==n[4]) return n[1]+180;
	
	if(n[0]==n[1]&&n[1]==n[2] &&n[3]==n[4]) return n[0]+160; 
	if(n[2]==n[3]&&n[3]==n[4] &&n[0]==n[1]) return n[2]+160;
	if(n[0]==n[1]&&n[1]==n[2]) return n[0]+140;
	if(n[1]==n[2]&&n[2]==n[3]) return n[1]+140;
	if(n[2]==n[3]&&n[3]==n[4]) return n[2]+140;
	
	if(n[1]==n[2] && n[3]==n[4]) return n[1]*2+n[3]*3+20;
	if(n[0]==n[1] && n[3]==n[4]) return n[0]*2+n[3]*3+20;
	if(n[0]==n[1] && n[2]==n[3]) return n[0]*2+n[2]*3+20;
	
	if(n[0]==n[1]) return n[0];
	if(n[1]==n[2]) return n[1];
	if(n[2]==n[3]) return n[2];
	if(n[3]==n[4]) return n[3];
	
	return 0;
}
int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T, z=1; cin >> T;
	while(T--){
		int n[5];
		rep(i, 0, 5) cin >> n[i];
		
		sort(n, n+5);
		
		printf("Teste %d\n", z++);
		printf("%d\n\n", ans(n));
	}
	
	
	return 0;
}

