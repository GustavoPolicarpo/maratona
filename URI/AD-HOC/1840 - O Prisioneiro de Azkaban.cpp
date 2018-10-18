// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Prisioneiro de Azkaban
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1840

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


int N;
string mesa;

string name[10]; int qt[10], sum[10];
map<char, int> mapa;

bool cmp(ii a, ii b){
	return a.S < b.S;
}

int ff(string s){
	if((mapa[s[0]]-1 == mapa[mesa[0]]) || (mapa[s[0]]-1 == -1 && mapa[mesa[0]]==9)){
		return 10*4+mapa[s[1]];
	}
	return mapa[s[0]]*4;
}

int main(){
	
	mapa['4']=0;
	mapa['5']=1;
	mapa['6']=2;
	mapa['7']=3;
	mapa['Q']=4;
	mapa['J']=5;
	mapa['K']=6;
	mapa['A']=7;
	mapa['2']=8;
	mapa['3']=9;
	mapa['D']=0;
	mapa['S']=1;
	mapa['H']=2;
	mapa['C']=3;
	
	cin >> N >> mesa;
	rep(i, 0, 4) cin >> name[i] >> qt[i];
	
	rep(i, 0, N){
		string A, B, C, D;
		cin >> A >> B >> C >> D;
		int pa=ff(A);
		int pb=ff(B);
		int pc=ff(C);
		int pd=ff(D);
		//cout << pa << " " << pb << " " << pc << " " << pd << '\n';
		
		int maior=max(pa, max(pb, max(pc, pd)));
		int cnt = 0;
		if(maior==pa) cnt++; if(maior==pb) cnt++; if(maior==pc) cnt++; if(maior==pd) cnt++;
		if(cnt==1){
			if(maior==pa) sum[0]++;
			if(maior==pb) sum[1]++;
			if(maior==pc) sum[2]++;
			if(maior==pd) sum[3]++;
		}
	}
	
	vector <ii> v;
	rep(i, 0, 4){
		//cout << sum[i] << '\n';
		v.pb(ii(i, abs(qt[i]-sum[i])));
	}
	
	sort(v.begin(), v.end(), cmp);
	if(v[0].S == v[1].S) puts("*");
	else cout << name[v[0].F] << "\n";
	
	return 0;
}
