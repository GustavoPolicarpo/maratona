// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Conversa não tão Secreta
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2302

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


int dx[]={0, 0, 0, 1, -1, -1, -1, 1, 1}, dy[]={0, 1, -1, 0, 0, -1, 1, -1, 1};

int main(){
	int N, M, X, Y, dir, px=0, py=0, ans=0, Q;
	
	scanint(N), scanint(M);
	scanint(X), scanint(Y);
	scanint(Q);
	
	while(Q--){
		scanint(dir);
		//cout << px << " " << py << '\n';
		px+=dx[dir], py+=dy[dir];
		
		rep(i, 0, 9){
			int ax=px+dx[i], ay=py+dy[i];
			if(ax==X && ay==Y){
				ans++;
				break;
			}
		}
			 
	}
	
	
	printf("%d\n", ans);
	
	
	
	return 0;
}

