// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Despojados
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2661

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

ll N;
vector <ll> v;

void div(){
	int fim = sqrt(N);
	rep(i, 1, fim+1){
		if(N%i==0){
			v.pb(i);
			if(i!=(N/i))
				v.pb(N/i);
		}
	}
}

bool check(ll n){
	int qt = 0, i=2, fim = sqrt(n);
	while(n>1){
		if(i>fim){
			qt++;
			break;
		}
		if(n%i==0){
			n/=i;
			qt++;
			if(n%i==0)
				return false;
		}
		i++;
	}
	return qt>=2;
}


int main(){
	
	scanf("%lld", &N);
	
	div();
	
	int ans = 0;
	rep(i, 0, v.size()){
		if(check(v[i]))
			ans++;
	}
	
	cout << ans << '\n';
	
	return 0;
}
