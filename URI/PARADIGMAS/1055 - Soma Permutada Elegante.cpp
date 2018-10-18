// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma Permutada Elegante
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1055

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

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < double, int > iii;


int main()
{
	int T; cin >> T;
	rep(z, 1, T+1){
		int n; cin >> n;
		int in[n];
		
		rep(i, 0, n)
			scanf("%d", &in[i]);
			
		sort(in, in+n);
		vector <int> out;
		
		out.pb(in[(n+1)/2-1]);
		out.pb(in[n-1]);
		rep(i, 0, (n)/2-1){
			out.pb(in[i]);
			out.pb(in[n-i-2]);	
		}
		if(n%2==1) out.pb(in[(n+1)/2-2]);

		int tt1=0;
		rep(i, 0, out.size()-1)
			tt1+=abs(out[i+1]-out[i]);	
		
		/******************************/ out.clear(); reverse(in, in+n);
		
		out.pb(in[(n+1)/2-1]);
		out.pb(in[n-1]);
		rep(i, 0, (n)/2-1){
			out.pb(in[i]);
			out.pb(in[n-i-2]);	
		}
		if(n%2==1) out.pb(in[(n+1)/2-2]);
		
		int tt2=0;
		rep(i, 0, out.size()-1)
			tt2+=abs(out[i+1]-out[i]);
		
			
		cout << "Case " << z << ": " << max(tt1,tt2) << endl;	
	}
	
return 0;
}



