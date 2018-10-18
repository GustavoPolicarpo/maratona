// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Quão Fácil é...
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1243

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

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < int, ii > iii;

void scanint(ll &x)
{
    register ll ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);





int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string in;
	while(getline(cin, in)){ in+=' ';
		int fim=in.size();
		int cnt=0; double media=0.0; string aux;
		rep(i, 0, fim){
			if(in[i]==' '){
				bool yep=true; int sub=0;
				rep(j, 0, aux.size()){
					if(!isalpha(aux[j])){
						if(j==aux.size()-1 && aux[j]=='.' && j!=0) {
							sub=1;
							continue;
						}
						yep=false;
						break;
					}
				}
				if(aux.size() && yep){
					cnt++;
					media+=aux.size()-sub;
				}
				aux="";
			}
			else aux+=in[i];
		}
		//cout << cnt << " " << media/cnt << endl;
		if(cnt==0) media=0;
		else		media/=cnt;
		
		if(media<4-error) puts("250");
		else if(media<6-error) puts("500");
		else puts("1000");
	}
	
return 0;

}
