// Author: Gustavo Policarpo
// Name: Throwing Balls
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1532

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
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
ll readInt();
int N, V;

bool check(int v){
	int cnt=v, p=0;
	while(p<=N && v>0){
		p+=v;
		if(p==N) return true;
		cnt--;
		if(cnt==0){
			v--;
			cnt=v;
		}
	}
	return false;	
}
int main(){
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d", &N, &V) and N){
		bool yep=false;
		rep(i, 1, V+1){
			if(check(i)){
				yep=true;
				break;
			}
		}
		if(yep) puts("possivel");
		else puts("impossivel");
	}
		
return 0;
}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}
