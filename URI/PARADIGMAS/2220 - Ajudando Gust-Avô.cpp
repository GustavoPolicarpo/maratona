// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ajudando Gust-Avô
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2220

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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

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



	char a[1000010], b[1000010], aux[1000100];
int main()
{
	int T; cin >> T; cin.ignore();
	while(T--){
	
		scanf("%s %s", a, b);
		int j=0, out=0, ta=strlen(a), tb=strlen(b);
		int ini=-1,  fim=ta, meio=(ini+fim)/2;;
		while(fim-ini>1){
			if(tb*meio>ta){
				fim=meio;
				meio=(ini+fim)/2;
				continue;
			} 	int cnt=0, tf=0;
			rep(i, 0, tb){
				rep(j, 0, meio+1)
					aux[cnt++]=b[i], tf++;
			} int taux=strlen(aux); //cout << aux <<  " " << tf << endl;
			j=0;
			rep(i, 0, ta){
				if(a[i]==aux[j]){
					j++;
					if(j==tf){
						out=meio+1;
						break;
					}
				}
			}
			if(j<tf){
				fim=meio;
				meio=(ini+fim)/2;
			}
			else{
				ini=meio;
				meio=(ini+fim)/2;
			}
		}
		printf("%d\n", out);
	}
	
	return 0;	
}
