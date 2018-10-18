// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2837

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 


int sz, add, pointer;
vector <ii> dq;
	
void push(int v){
	int qt = 0;
	while(dq.size()>pointer && dq.back().F+add>=v){
		qt+=dq.back().S+1;
		dq.pop_back();
	}
	dq.push_back(ii(v-add, qt));
	sz++;
}
void remove(){
	if(!sz) return;
	if(dq[pointer].S==0) pointer++;
	else dq[pointer].S--;
	sz--;
}
void plus(int v){
	add+=v;
}
int get_min(){
	if(!sz) return 0x3f3f3f3f;
	return dq[pointer].F+add;
}
void erase(){
	vector <ii> er;
	swap(dq, er);
	sz = 0;
	add = 0;
	pointer = 0;
}

int N, L, H, s[100010], m[100010], sa[100010], sm[100010], ans[100010], resp=-0x3f3f3f3f;
ii c[100010];

int main(){
	
	scanf("%d %d %d", &N, &L, &H); dq.reserve(N+2);
	rep(i, 1, N+1) scanf("%d", &s[i]), sa[i] = sa[i-1]+s[i];
	rep(i, 1, N+1) scanf("%d", &m[i]), sm[i] = sm[i-1]+m[i];
	
	//rep(i, 1, N+1) cout << sa[i] << " "; cout << '\n';
	
	int a1 = 1, a2 = 1;
	rep(i, 1, N+1){
		while(a1<=i && sm[i]-sm[a1-1]>H) a1++;
		while(a2<=i && sm[i]-sm[a2-1]>=L) a2++; if(a2) a2--;
		a1 = min(a1, a2);
		c[i] = ii(a1, a2);
	}
	
	a1 = 1, a2 = 1;
	rep(i, 1, N+1){
		while(a2<=c[i].S) push(sa[a2-1]), a2++;
		while(a1<c[i].F) remove(), a1++;
		ans[i] = sa[i]-get_min();
		//cout << c[i].F << " " << c[i].S << " " << a1 << " " << a2 << " " << sa[i] << " " << get_min() << " " << ans[i] << '\n';
		resp = max(resp, ans[i]);
	}
	
	printf("%d\n", resp);
	
	
	return 0;
}  
