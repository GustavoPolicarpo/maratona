// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogo do Bicho
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1483

//#define gc getchar_unlocked
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
#define MAXN 100001
#define mod 1000000007
#define error 1e-2
#define pi acos(-1)

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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
//


int main()
{
	double V, out; int N, M; string n, m;
	while(cin >> V >> n >> m){
		if(V<0.01) break;
		if(n.size()<4){
			reverse(n.begin(), n.end());
			while(n.size()<4){
				n+='0';
			}
			reverse(n.begin(), n.end());
		}
		if(m.size()<4){
			reverse(m.begin(), m.end());
			while(m.size()<4){
				m+='0';
			}
			reverse(m.begin(), m.end());
		}
		int cnt=0, i=n.size()-4, j=m.size()-4;
		rep(k, 0, 4){
			if(n[i++]==m[j++]) cnt++;
			else cnt=0;
		}
		if(cnt==4) out=V*3000.0;
		else if(cnt==3) out=V*500.0;
		else if(cnt==2) out=V*50.0;
		else{
			N=0, M=0;
			rep(i, n.size()-2, n.size()){
				N*=10;
				N+=n[i]-'0';
			}
			if(N==0) N=100;
			if(N%4==0) N--;
			rep(i, m.size()-2, m.size()){
				M*=10;
				M+=m[i]-'0';
			}	
			if(M==0) M=100;
			if(M%4==0) M--;
			if(N/4==M/4) out=V*16.0;
			else out=0.0;
		}
		printf("%.2lf\n", out);
				
	}
	
	return 0;
}

