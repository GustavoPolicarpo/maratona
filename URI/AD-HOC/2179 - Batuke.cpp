// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Batuke
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2179

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


int mat[200][200];

int get(int x, int y){
	return mat[x+50][y+50];
}
int main()
{
	memset(mat, 0, sizeof mat);
	int N, x, y, cnt=1, cont=1;
	scanf("%d %d %d", &N, &x, &y);
	rep(i, 0, N)
	rep(j, 0, N)
		mat[i+50][j+50]=cnt++;
		
	vector <int> out; cnt=1;
	out.pb(get(x, y));
	
	while(1){
		if(cnt&1){
			rep(i, 0, cnt){
				y++, cont++;
				if(get(x, y)!=0) out.pb(get(x, y));
				if(out.size()>=N*N) break;		
			}
			if(out.size()>=N*N) break;	
			rep(i, 0, cnt){
				x++, cont++;
				if(get(x, y)!=0) out.pb(get(x, y));
				if(out.size()>=N*N) break;		
			}
		}
		else{
			rep(i, 0, cnt){
				y--, cont++;
				if(get(x, y)!=0) out.pb(get(x, y));
				if(out.size()>=N*N) break;		
			}
			if(out.size()>=N*N) break;	
			rep(i, 0, cnt){
				x--, cont++;
				if(get(x, y)!=0) out.pb(get(x, y));
				if(out.size()>=N*N) break;		
			}
		
		}
		if(out.size()>=N*N) break;	
		cnt++;	
	}
	
	rep(i, 0, out.size()){
		if(i>0) printf(" ");
		printf("%d", out[i]);
	}
	printf("\n%d\n", cont);
	
		
return 0;
}
