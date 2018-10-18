// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Hall dos Assassinos
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1861

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
	puts("HALL OF MURDERERS");
	set <string> morreu;
	map <string, int> matou;
	map <string, int>:: iterator it;
	
	string kill, die;
	while(cin >> kill >> die){
		//if(kill=="arrozdoce") break;
		morreu.insert(die);
		matou[kill]++;
	}
	
	for(it=matou.begin(); it!=matou.end(); it++){
		if(morreu.count(it->first)) continue;
		cout << it->first << " " << it->second << '\n';
	}
	
	
return 0;

}
