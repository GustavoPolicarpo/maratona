// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Matring
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1803

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
//#define mod 1000000007 

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
	vector <string> in; string p;
	rep(i, 0, 4){
		cin >> p;
		in.pb(p);
	}
	int fim=p.size();
	int F=0, L=0, aux, mod=257;
	rep(i, 0, 4){
		F*=10;
		F+=in[i][0]-'0';
	}
	F%=mod;
	rep(i, 0, 4){
		L*=10;
		L+=in[i][fim-1]-'0';
	}
	L%=mod;
	rep(i, 1, fim-1){
		aux=0;
		rep(j, 0, 4){
			aux*=10;
			aux+=in[j][i]-'0';
		}
		//x	cout << aux << endl;
		aux%=mod;
		aux=(F*aux+L)%mod;
		
		char c=aux;
		cout << c;
	}
	cout << endl;
		
		
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
