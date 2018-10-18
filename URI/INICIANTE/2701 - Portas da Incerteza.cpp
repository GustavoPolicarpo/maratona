// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Portas da Incerteza
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2701

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < ii, ii > iii;


const ll mod = 1000000007;

struct use{
	ll a, b, c, d;
};

/*
0 0
0 1
1 0
1 1
*/

use M(ll a, ll b, ll c, ll d){
	use ret;
	ret.a=a, ret.b=b, ret.c=c, ret.d=d;
	return ret;
}

int il[100010], ir[100010], io[100010], n;

use solve(int u){
	
	if(u==0) return M(1, 0, 0, 1);
	
	use ret, L = solve(il[u]), R = solve(ir[u]);
	
	if(io[u]==0){
		ret.a = (L.c+L.d)*(R.c+R.d);
		ret.b = 0;
		ret.c = (L.a+L.b+L.c+L.d)*(R.a+R.b+R.c+R.d) - ret.a;
		ret.d = 0;
	}
	else if(io[u]==1){
		ret.a = 0;
		ret.b = (L.c+L.d)*(R.c+R.d);
		ret.c = 0;
		ret.d = (L.a+L.b+L.c+L.d)*(R.a+R.b+R.c+R.d) - ret.b;
	}
	else{
		ret.a = (L.d)*(R.d);
		ret.b = (L.c)*(R.c+R.d) + (R.c)*(L.d);
		ret.c = (L.b)*(R.b+R.d) + (R.b)*(L.d);
		ret.d = (L.a)*(R.a+R.b+R.c+R.d) + (R.a)*(L.b+L.c+L.d) + L.b*R.c + R.b*L.c;
	}
	
	ret.a%=mod;
	ret.b%=mod;
	ret.c%=mod;
	ret.d%=mod;
	
	/*cout << il[u] << " : " << L.a << " " << L.b << " " << L.c << " " << L.d << '\n';
	cout << ir[u] << " : " << R.a << " " << R.b << " " << R.c << " " << R.d << '\n';
	cout << u << " : " << ret.a << " " << ret.b << " " << ret.c << " " << ret.d << '\n';
	cout << "*****\n";*/
	
	return ret;
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanf("%d", &n);
	rep(i, 1, n+1) scanf("%d %d %d", &il[i], &ir[i], &io[i]);
	
	use ans = solve(1);
	//cout << ans.a << " " << ans.b << " " << ans.c << " " << ans.d << '\n';
	cout << (ans.b+ans.c)%mod << '\n';
	
	return 0;
}
