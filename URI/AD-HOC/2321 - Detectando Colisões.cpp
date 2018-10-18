// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Detectando Colisões
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2321

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

#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	ii a[2], b[2];
	rep(i, 0, 2) cin >> a[i].F >> a[i].S;
	rep(i, 0, 2) cin >> b[i].F >> b[i].S;
	
	if((((b[0].F >= a[0].F && b[0].F <=a[1].F) || (b[1].F >=a[0].F && b[1].F <=a[1].F)) &&
		b[0].S <= a[1].S && b[1].S >=a[0].S) ||
	   (b[0].F <= a[1].F && b[1].F >=a[0].F &&
		((b[0].S >= a[0].S && b[0].S <=a[1].S) || (b[1].S >=a[0].S && b[1].S <=a[1].S)))){
			puts("1");
			return 0;
		}
		
	rep(i, 0, 2) swap(a[i], b[i]);
	
	if((((b[0].F >= a[0].F && b[0].F <=a[1].F) || (b[1].F >=a[0].F && b[1].F <=a[1].F)) &&
		b[0].S <= a[1].S && b[1].S >=a[0].S) ||
	   (b[0].F <= a[1].F && b[1].F >=a[0].F &&
		((b[0].S >= a[0].S && b[0].S <=a[1].S) || (b[1].S >=a[0].S && b[1].S <=a[1].S)))){
			puts("1");
			return 0;
		}
		
	
	
	puts("0");
	
	return 0;
	
}
