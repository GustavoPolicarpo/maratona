// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Bits Trocados
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2187

#define gc getchar_unlocked
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
typedef pair < int, double > iii;

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
	int V, z=1, v[]={50, 10, 5, 1};
	while(scanf("%d", &V) and V){
		int n[4], i=0; memset(n, 0, sizeof n);
		while(V){
			if(V>=v[i]){
				V-=v[i];
				n[i]++;
			}
			else i++;
		}	
		
		printf("Teste %d\n", z++);
		printf("%d %d %d %d\n\n", n[0], n[1], n[2], n[3]);
	
	}
	
		
return 0;
}
