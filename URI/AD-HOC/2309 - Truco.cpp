// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Truco
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2309

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




int C(int n){
	if(n==4) return 0;
	if(n==5) return 1;
	if(n==6) return 2;
	if(n==7) return 3;
	if(n==12) return 4;
	if(n==11) return 5;
	if(n==13) return 6;
	if(n==1) return 7;
	if(n==2) return 8;
	if(n==3) return 9;
}
int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N, aa=0, a, bb=0, b, aux, al[3], bl[3]; 
	
	scanint(N);
	
	rep(i, 0, N){
		a=0, b=0;
				
		rep(j, 0, 3)
			scanint(aux), al[j]=C(aux);

		
		rep(j, 0, 3){
			scanint(aux), bl[j]=C(aux);
			al[j]>=bl[j] ? a++ : b++;
		}
	
		a > b ? aa++ : bb++;
		
	}
	
	printf("%d %d\n", aa, bb);
	
	return 0;
}

