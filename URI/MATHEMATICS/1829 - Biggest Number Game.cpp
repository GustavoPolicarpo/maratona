// Author: Gustavo Policarpo
// Name: Biggest Number Game
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1829

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

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < int, ii > iii;

void scanint(ll &x)
{
    register ll ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);





int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N; cin >> N;
	char aux[15]; int fim, n, e, b, aa=0, bb=0; double na, nb; vector <int> out;
	while(N--){
		scanf("%s", aux); fim=strlen(aux), n=0;
		rep(i, 0, fim){
			if(!isdigit(aux[i])){
				b=n;
				n=0;
				continue;
			}
			n*=10;
			n+=aux[i]-'0';
		} 		e=n;
		na=e*log(b);
		//cout << na << endl;
		
		scanf("%s", aux); fim=strlen(aux), n=0, nb=0;
		rep(i, 0, fim-1){
			n*=10;
			n+=aux[i]-'0';
		} 		b=n;
		rep(i, 1, b+1){
			nb+=log(i);
		}
		//cout << nb << endl;
		
		if(na>nb) aa++, out.pb(0);
		else if(nb>na) bb++, out.pb(1);
		else out.pb(2);
	}
	if(aa>bb) puts("Campeao: Lucas!");
	else if(bb==aa) puts("A competicao terminou empatada!");
	else puts("Campeao: Pedro!");
	rep(i, 0, out.size()){
		printf("Rodada #%d: ", i+1);
		if(out[i]==0) puts("Lucas foi o vencedor");
		else puts("Pedro foi o vencedor");
	}
	/*cout << log(10)+log(5) << endl;
	cout << log(50) << endl;
	cout << log(pow(5, 5)) << endl;
	cout << 5*log(5);*/
	
return 0;

}
