// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Extremamente Básico
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1001

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;


const int tmax = 2020;
int st[tmax * 4][tmax * 4], sizem=2002;
// Do not forget to set â€™sizemâ€™, which is equal to the second dimension size
// Implicit function, DO NOT CALL IT!
int gety( int nodex, int nodey, int iniy, int fimy, int y, int y1 )
{
    if( y > fimy || y1 < iniy || iniy > fimy ) return 0;
    if( y <= iniy && y1 >= fimy ) return st[nodex][nodey];
    int mid = (iniy+fimy)/2;
// Choose any associative operation you want!!
    return __gcd(gety(nodex,nodey*2,iniy,mid,y,y1) , gety(nodex,nodey*2 + 1,mid+1,fimy,y
            ,y1));
}
// Call this function to get whatever you want in the rectangle ((x,y),(x1,y1))
int get( int nodex, int inix, int fimx, int x, int y, int x1, int y1)
{
    if( x > fimx || x1 < inix || inix > fimx) return 0;
    if( x <= inix & x1 >= fimx ) return gety(nodex,1,0,sizem-1,y,y1);
    int mid = (inix + fimx)/2;
    return __gcd(get(nodex*2,inix,mid,x,y,x1,y1) , get(nodex*2+1,mid+1,fimx,x,y,x1,y1));
}
// Implicit function, DO NOT CALL IT!
void updatey( int nodex, int inix, int fimx, int nodey, int iniy, int fimy, int
              y, int val )
{
    if( iniy == fimy )
    {
        if( inix == fimx ) st[nodex][nodey] = val;
        else st[nodex][nodey] = st[nodex*2][nodey] + st[nodex*2+1][nodey];
        return;
    }
    int mid = (iniy+fimy)/2;
    if( y <= mid ) updatey(nodex,inix,fimx,nodey*2,iniy,mid,y,val);
    else updatey(nodex,inix,fimx,nodey*2+1,mid+1,fimy,y,val);
    st[nodex][nodey] = __gcd(st[nodex][nodey*2] , st[nodex][nodey*2+1]);
}
// Call this function to update a position (x,y)
void update( int nodex, int inix, int fimx, int x, int y, int val)
{
    if( inix != fimx )
    {
        int mid = (inix+fimx)/2;
        if( x <= mid ) update(nodex*2,inix,mid,x,y,val);
        else update(nodex*2+1,mid+1,fimx,x,y,val);
    }
    updatey(nodex,inix,fimx,1,0,sizem-1,y,val);
}


int main()
{
	
	int a, b;
	cin >> a >> b;
	cout << "X = " << a+b << '\n';
	return 0;
	int Q;
	
	while(scanf("%d", &Q)!=EOF){
		
		memset(st, 0, sizeof st);
		char s[10]; int x, y, d;
		
		while(Q--){
			scanf("%s %d %d %d", s, &x, &y, &d);
			x+=750, y+=750;
			x=x+y-500, y=x-y+500;
			
			if(s[0]=='S'){
				update(1, 0, 2000, x, y, d);
			}else{
				printf("%d\n", get(1, 0, 2000, max(x-d, 0), max(y-d, 0), min(x+d, 2000), min(y+d, 2000)));
			}
		}
		
	}
	
	return 0;
	
}
