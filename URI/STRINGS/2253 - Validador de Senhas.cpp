// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Validador de Senhas
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2253

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
	while(getline(cin, in)){
		if(in.size()<6 || in.size()>32){
			puts("Senha invalida.");
			continue;
		}
		int a=0, b=0, c=0, d=0;
		rep(i, 0, in.size()){
			if(isdigit(in[i])) a++;
			else if(isalpha(in[i])){
				if(islower(in[i])) b++;
				else c++;
			}
			else d++;
		}
		if(a>0&&b>0&&c>0&&d==0) puts("Senha valida.");
		else puts("Senha invalida.");
	}
	
return 0;
}
