// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Transporte de Painéis Sol...
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1579

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

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T, ans; cin >> T;
	int n, c, price, v[101], MAX, sum;
	while(T--){
		scanf("%d %d %d", &n, &c, &price); sum=0, MAX=0;
		rep(i, 0, n) scanf("%d", &v[i]), sum+=v[i], MAX=max(MAX, v[i]);
		
		sum/=c, sum=max(sum, MAX);
		MAX*=n+1, ans=INF;
		
		int ini=sum, fim=MAX;
		while(ini<=fim){
			int use=(ini+fim)/2, aux=0, i=0, cnt=0, yep=1;
			
			for(; i<n; i++){
				if(aux+v[i]<=use) aux+=v[i];
				else if(aux+v[i]>aux){
					cnt++;
					if(cnt>c){
						yep=0;
						break;
					}
					aux=v[i];
				}
			}
				
			if(cnt==c && aux) yep=0;
			
			if(yep)	ans=use, fim=use-1;
			else ini=use+1;
			
		}
		
		printf("%d $%d\n", ans, ans*c*price);
		
	}
	
	return 0;
	
}
