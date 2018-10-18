// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Anagramas
// Nível: 4
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2828

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

#define INF 0x3f3f3f3f

ll mod = 1e9+7;
ll fat[10000005];

ll fastexp(ll a,int b){
	ll ret=1;
	while(b){
		if(b&1) ret=(ret*a)%mod;
		b>>=1;
		a=(a*a)%mod;
	}
	return ret;
}

ll inverso(ll a) { return fastexp(a,mod-2); }

ll combina(ll n, ll k){  
 
   ll num = fat[n];
   ll den = inverso( (fat[k] * fat[n - k]) % mod );
   
   ll ret = (num * den) % mod;

   return ret;
}

int main(){
	
	fat[0]=1; rep(i, 1, 100001) fat[i]=(fat[i-1]*i)%mod;
	
	string s;
	while(cin >> s){
		if(s=="0") break;
		
		vector <int> freq(28, 0); int tam=s.size();
		rep(i, 0, tam) freq[s[i]-'a']++;
		
		ll ans=1;
		rep(i, 0, 26){
			if(!freq[i]) continue;
			ans*=combina(tam, freq[i]);
			ans%=mod;
			tam-=freq[i];
		}
		
		cout << ans << '\n';
		
		break;
		
	}
	
	
	return 0;
}
