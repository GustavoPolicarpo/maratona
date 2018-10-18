// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cortador de Pizza
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2878

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

vector <ii> h, v;
int bit[200020];

bool cmp(ii a, ii b){
	return a.S < b.S;
}


int query(int x){
	int ret = 0;
	for(; x>0; x-=x&-x) ret+=bit[x];
	return ret;
}

void update(int x){
	for(; x<100010; x+=x&-x) bit[x]++;
}

int main(){
	
	int X, Y, H, V, x, y, add; ll ans = 0;
	scanf("%d %d", &X, &Y);
	scanf("%d %d", &H, &V);
	
	ans += (ll)(H+1)*(ll)(V+1);
	
	rep(i, 0, H){
		scanf("%d %d", &x, &y);
		h.pb(ii(x, y));
	}
	sort(h.begin(), h.end(), cmp);
	rep(i, 0, h.size()) h[i].S = i+1;
	sort(h.begin(), h.end());
	memset(bit, 0, sizeof bit);
	rep(i, 0, h.size()){
		ans += abs(query(h[i].S)-i);
		update(h[i].S);
	}
	
	
	int xx = ans;
	rep(i, 0, V){
		scanf("%d %d", &x, &y);
		v.pb(ii(x, y));
	}
	sort(v.begin(), v.end(), cmp);
	rep(i, 0, v.size()) v[i].S = i+1;
	sort(v.begin(), v.end());
	memset(bit, 0, sizeof bit);
	rep(i, 0, v.size()){
		ans += abs(query(v[i].S)-i);
		update(v[i].S);
	}
	
	cout << ans << '\n';
	
	return 0;
} 
