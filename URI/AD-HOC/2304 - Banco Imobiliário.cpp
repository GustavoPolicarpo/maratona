// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Banco Imobiliário
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2304

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

int C(char c){
	if(c=='D') return 0;
	if(c=='E') return 1;
	return 2;
}
int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int I, N, n[3];
	cin >> I >> N;
	rep(i, 0, 3) n[i]=I;
	
	while(N--){
		char op, pa, pb; int v;
		cin >> op;
		if(op=='C'){
			cin >> pa >> v;
			n[C(pa)]-=v;
		}
		else if(op=='V'){
			cin >> pa >> v;
			n[C(pa)]+=v;
		}
		else{
			cin >> pa >> pb >> v;
			n[C(pa)]+=v;
			n[C(pb)]-=v;
		}
	}
	
	printf("%d %d %d\n", n[0], n[1], n[2]);
	
	
	return 0;
}

