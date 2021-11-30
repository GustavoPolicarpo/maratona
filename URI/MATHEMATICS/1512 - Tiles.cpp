// Author: Gustavo Policarpo
// Name: Tiles
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1512

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
ll readInt();
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
	int N, A, B;
	while(1){
		N=readInt(), A=readInt(), B=readInt();
		if(N==0) break;
		ll out=0;
		out+=N/A+N/B;
	//	cout << out << endl;
		ll sub=N/(A/__gcd(A, B)*B);
	//	cout << sub << endl;
		out-=sub;
		printf("%lld\n", out);
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

