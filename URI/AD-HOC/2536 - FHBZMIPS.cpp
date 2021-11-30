// Author: Gustavo Policarpo
// Name: FHBZMIPS
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2536

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

struct use{
	string op; int id, a, b;
};
int main()
{
	
	int n;
	
	while(scanf("%d", &n)!=EOF){
		vector <use> v; use aux;
		
		rep(i, 0, n){
			cin >> aux.id >> aux.op;
			if(aux.op=="gotoif") cin >> aux.a >> aux.b;
			else if(aux.op!="halt") cin >> aux.a;
			v.pb(aux);
		}
		
		int ans=0, vis[n+2][260], p=0;
		memset(vis, 0, sizeof vis);
		
		while(1){
			
			if(vis[p][ans]){
				ans=-1;
				break;
			}
			
			vis[p][ans]=1, aux=v[p++];
			
			if(aux.op=="halt") break;
			else if(aux.op=="gotoif"){
				if(ans>=aux.a) p=aux.b-1;
			}
			else if(aux.op=="add") ans+=aux.a;
			else if(aux.op=="sub") ans-=aux.a;
			else if(aux.op=="mul") ans*=aux.a;
			else if(aux.op=="div") ans/=aux.a;
			else if(aux.op=="and") ans&=aux.a;
			else if(aux.op=="or") ans|=aux.a;
			else if(aux.op=="xor") ans^=aux.a;
			
			while(ans<0) ans+=256; ans%=256;
			
		}
		
		if(ans==-1) puts("execucao infinita");
		else printf("%d\n", ans);
		
		
	}
	

	return 0;
	
}
