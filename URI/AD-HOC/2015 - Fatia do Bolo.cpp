// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fatia do Bolo
// Nível: 6
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2015

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


//freopen("out.txt", "w", stdout);

struct ponto{
	ll x, y;
};

ll area_total(ponto *n, int N){
	ll ans=0;
	rep(i, 0, N)
		ans+= (n[i].x*n[i+1].y - n[i].y*n[i+1].x);
	return abs(ans);
}

ll determinante(ponto a, ponto b, ponto c){
	return (a.x*b.y + a.y*c.x + b.x*c.y) - 
			(b.y*c.x + a.y*b.x + a.x*c.y);
}
ll area_triangulo(ponto a, ponto b, ponto c){
	return abs(determinante(a, b, c));
}

ponto n[2*100010];
int main()
{
	//freopen("in.txt", "r", stdin);
	int N; cin >> N;
	
	rep(i, 0, N) scanf("%lld %lld", &n[i].x, &n[i].y), n[N+i]=n[i];
	
	ll at=area_total(n, N); //cout << at << '\n';
	
	ll ans[N], atual=area_triangulo(n[0], n[1], n[2]), a=max(at-atual, atual), b=at-a; 
	ans[0]=a; int i=0, j=2; 
	
	while(i<N){
		//cout << i << " " << j << " "  << atual << " " << a << " " << b << '\n';
		//system("pause");
		ll nt=area_triangulo(n[i], n[j], n[j+1]);
		if(atual + nt >= a){
			i++, j++;
			atual+=nt;
			atual-=area_triangulo(n[i-1], n[i], n[j]);
			a=max(at-atual, atual), b=at-a; 
			ans[i]=a;
		}else{
			j++;
			atual+=nt;
			a=max(at-atual, atual), b=at-a; 
			ans[i]=a;
		}
		
		while(j>i+2){
			ll aux=atual-area_triangulo(n[i], n[j-1], n[j]);
			ll aa=max(aux, at-aux), bb=at-aa;
			if(bb >= b){
				j--;
				atual=aux, a=aa, b=bb;
				ans[i]=a;
			}else{
				break;
			}
		}
		
	}

	ll out=0;
	rep(i, 0, N) out=max(out, ans[i]);
	
	printf("%lld %lld\n", out, at-out);
	
	return 0;
	
}
