// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogo do Operador
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2493

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct game{
	int a, b, c;
};
int main()
{
	int N; 
	while(cin >> N){
		vector <game> in;
		game aux;
		rep(i, 0, N){
			scanf("%d %d=%d", &aux.a, &aux.b, &aux.c);
			in.pb(aux);
		}
		vector <string> out;
		string name; int num; char op;
		rep(i, 0, N){
			cin >> name >> num >> op;
			aux=in[num-1];
			if(op=='+'){
				if(aux.a+aux.b!=aux.c)
				out.pb(name);
			}
			else if(op=='-'){
				if(aux.a-aux.b!=aux.c)
				out.pb(name);
			}
			else if(op=='*'){
				if(aux.a*aux.b!=aux.c)
				out.pb(name);
			}
			else if(op=='I'){
				if(aux.a+aux.b==aux.c || 
					aux.a-aux.b==aux.c ||
					aux.a*aux.b==aux.c)
				out.pb(name);
			}
		}
		
		if(out.size()==0) puts("You Shall All Pass!");
		else if(out.size()==N) puts("None Shall Pass!");
		else{
			sort(out.begin(), out.end());
			rep(i, 0, out.size()){
				if(i) cout << " ";
				cout << out[i];
			}
			cout << '\n';
		}
		
		
	}



return 0;
}
