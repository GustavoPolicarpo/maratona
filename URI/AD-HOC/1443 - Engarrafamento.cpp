// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Engarrafamento
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1443

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

int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N; 
	while(1){
		scanf("%d", &N); if(!N) break;
		double ds=0.0, t, v=0.0; int i, j, aux=0;
		while(N--){
			scanf("%d %d", &i, &j);
			t=i-aux;
			if(v-2*t<0.0){
				t=v/2.0;
				ds+=(v*t)/2.0;
				v=0.0;
			}
			else{
				ds+=(v+v-2*t)*t/2.0;
				v=v-2*t;
			}
			t=j-i;
			if(v+t>10){
				ds+=(10+v)*(10-v)/2.0;
				t=t-(10-v);	
				v=10;
				ds+=t*10;
			}
			else{
				ds+=(v+t+v)*(t)/2.0;
				v=v+t;
			}
			aux=j;
		}
		printf("%.2lf\n", ds);
	}
	
return 0;
}
