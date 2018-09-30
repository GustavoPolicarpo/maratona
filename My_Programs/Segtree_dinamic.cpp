#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
#define gc getchar
#define pc(x) putchar(x);

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << m[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;

using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

void scanint(register int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

struct node{
	int qt;
	int left, righ;
};

node new_node(){
	node ret;
	ret.qt=ret.left=ret.righ=0;
	return ret;
}
vector <node> tree[100010];

int query(int no, int op, int le, int ri, int a, int b){
	
	if(no >= tree[op].size()) return 0;
	if(le > b || ri < a) return 0;
	if(le>=a && ri<=b) return tree[op][no].qt;
	
	int sl=0, sr=0;
	int mi=(le+ri)/2;
	if(tree[op][no].left) sl=query(tree[op][no].left, op, le, mi, a, b);
	if(tree[op][no].righ) sr=query(tree[op][no].righ, op, mi+1, ri, a, b);
	
	return sl+sr;
}

void update(int no, int op, int le, int ri, int k){
	if(no==tree[op].size())	tree[op].pb(new_node());
	
	if(le > k || k>ri) return;
	
	if(le==ri && le==k){
		tree[op][no].qt++;
		return;
	}
	
	int mi=(le+ri)/2;
	if(k<=mi){
		if(tree[op][no].left) update(tree[op][no].left, op, le, mi, k);
		else{
			tree[op][no].left=tree[op].size();
			update(tree[op][no].left, op, le, mi, k);
		}
	}
	else if(k>=mi+1){
		if(tree[op][no].righ) update(tree[op][no].righ, op, mi+1, ri, k);
		else{
			tree[op][no].righ=tree[op].size();
			update(tree[op][no].righ, op, mi+1, ri, k);
		}
	}
	tree[op][no].qt = 0;
	if(tree[op][no].left) tree[op][no].qt += tree[op][tree[op][no].left].qt;
	if(tree[op][no].righ) tree[op][no].qt += tree[op][tree[op][no].righ].qt;
	
}

vector <int> primes, eh(400, 1);
void crivo(){
	for(int i=2; i<=20; i++){
		if(!eh[i]) continue;
		for(int j=i*i; j<400; j+=i)
			eh[j] = 0;
	}
	for(int i=2; i<=400; i++)
		if(eh[i])
			primes.pb(i);
	//rep(i, 0, primes.size()) cout << primes[i] << '\n';
}

ii pd[100010];
vector <int> position[100010];
int N, Q, tam;


void build(int p, int n, int pos){
	if(p==tam){
		position[n].pb(pos);
		//update(0, n, 0, N-1, pos);
		return;
	}
	build(p+1, n, pos);
	rep(i, 0, pd[p].S){
		n = n*pd[p].F;
		build(p+1, n, pos);
	}
	return;
}

int main(){
	
	crivo();
	
	int aux, j;
	
	scanint(N), scanint(Q);
	
	rep(i, 0, N){
		scanint(aux); j = 0; tam = 0;
		while(aux>1 && j<primes.size()){
			if(aux%primes[j]==0){
				int cnt = 0;
				while(aux%primes[j]==0){
					cnt++;
					aux/=primes[j];
				}
				pd[tam++] = (ii(primes[j], cnt));
			}
			j++;
		}
		
		if(aux>1) pd[tam++] = (ii(aux, 1));
		build(0, 1, i);
		
	}
	
	int l, r, k, ai, ar; 
	while(Q--){
		scanint(l), scanint(r), scanint(k); l--, r--;
		ai = lower_bound(position[k].begin(), position[k].end(), l) - position[k].begin();
		ar = upper_bound(position[k].begin(), position[k].end(), r) - position[k].begin();
		printf("%d\n", ar-ai);
		//printf("%d\n", query(0, k, 0, N-1, l, r));
	}
	
	return 0;
}
