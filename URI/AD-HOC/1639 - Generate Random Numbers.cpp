// Author: Gustavo Policarpo
// Name: Generate Random Numbers
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1639

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
ll readInt();
ll N;

char alfa[]={"0123456789"};
int main(){
	while(1){
		N=readInt();
		if(!N) break;
		set <int> num; 
			
		while(1){
			if(num.count(N)) break;
			num.insert(N);
			ll aux=N*N;
			string tempo="";
			while(aux>=1){
				tempo+=alfa[aux%10];
				aux/=10;
			}
			while(tempo.size()<8) tempo+='0';
			reverse(tempo.begin(), tempo.end());
			
			aux=0;
			rep(i, 2, 6){
				aux*=10; 
				aux+=tempo[i]-'0';
			}
			N=aux;
		}
		
		cout << num.size() << endl;
		
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
