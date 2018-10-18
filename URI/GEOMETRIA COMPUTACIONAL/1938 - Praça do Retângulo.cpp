// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Praça do Retângulo
// Nível: 4
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1938

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
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

ll readInt();
struct ponto{
	int x, y;
};

bool dentro(ponto a, ponto b, ponto k)
{
	return k.x>=min(a.x, b.x) && k.x<=max(a.x, b.x) &&
			k.y>=min(a.y, b.y) && k.y<=max(a.y, b.y);	
}

bool cmp(ponto a, ponto b)
{
	if(a.x<b.x) return true;
	if(a.x>b.x) return false;
	if(a.y<b.y) return true;
	return false;	
}

int main()
{
	int N; N=readInt();
	vector < ponto > pt;
	ponto aux;
	rep(i, 0, N){
		aux.x=readInt(), aux.y=readInt();
		pt.pb(aux);
	}
	sort(pt.begin(), pt.end(), cmp);
	
	int cont=0;
	rep(i, 0, N){
		int ymin=-INF, ymax=INF;
		rep(j, i+1, N){
			if(pt[j].y>ymin && pt[j].y<ymax){
				cont++;
				if(pt[j].y<pt[i].y) ymin=pt[j].y;
				else ymax=pt[j].y;
			}	
		}
	}
	printf("%d\n", cont);
		
return 0;
}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}
