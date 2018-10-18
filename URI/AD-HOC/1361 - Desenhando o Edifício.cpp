// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Desenhando o Edifício
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1361

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
vector <int> azul, verm;

int solve(int i, int j, int l){
	int ret=0;
	if(l==0){
		if(verm.size()==0) return 0;
		while(verm[j]>=azul[i]){
			j++;
			if(j==verm.size()) return 0;
		}
		ret+=solve(i, j, 1)+1;
	}
	
	else{
		if(azul.size()==0) return 0;
		while(azul[i]>=verm[j]){
			i++;
			if(i==azul.size()) return 0;
		}
		ret+=solve(i, j, 0)+1;
	}
	return ret;
}

int main(){
	int P; P=readInt();
	while(P--){
		azul.clear(), verm.clear();
		int Q, aux; Q=readInt();
		while(Q--){
			aux=readInt();
			if(aux<0) verm.pb(abs(aux));
			else azul.pb(aux);
		}
		
		sort(azul.begin(), azul.end());
		reverse(azul.begin(), azul.end());
		sort(verm.begin(), verm.end());
		reverse(verm.begin(), verm.end());
		
		int out=0;
		if(azul.size()!=0)
			out=max(out, solve(0, 0, 0)+1);
		if(verm.size()!=0)	
			out=max(out, solve(0, 0, 1)+1);
		printf("%d\n", out);
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
