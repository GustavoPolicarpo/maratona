// Author: Gustavo Policarpo
// Name: Rectangle Park
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1938

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
typedef pair < double, int > iii;
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}



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
	int N; cin >> N;
	vector < ponto > pt;
	ponto aux;
	rep(i, 0, N){
		scanint(aux.x), scanint(aux.y);
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
