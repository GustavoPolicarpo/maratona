// Author: Gustavo Policarpo
// Name: Arya's Death List
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1856

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
typedef pair < char, ii > iii;


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


struct no{
	int x;
	deque <ii> r;
};

no in[120120];

struct node{
	int qt;
	int left, righ;
};

node new_node(){
	node ret;
	ret.qt=ret.left=ret.righ=0;
	return ret;
}
vector <node> tree;

int query(int no, ll le, ll ri, ll a, ll b){
	
	if(no >= tree.size()) return 0;
	if(le > b || ri < a) return 0;
	if(le>=a && ri<=b) return tree[no].qt;
	
	int sl=0, sr=0;
	ll mi=(le+ri)/2;
	if(tree[no].left) sl=query(tree[no].left, le, mi, a, b);
	if(tree[no].righ) sr=query(tree[no].righ, mi+1, ri, a, b);
	
	return sl+sr;
}

void update(int no, ll le, ll ri, ll k, int v){
	if(no==tree.size())	tree.pb(new_node());
	
	if(le > k || k>ri) return;
	
	if(le==ri && le==k){
		tree[no].qt+=v;
		return;
	}
	
	ll mi=(le+ri)/2;
	if(tree[no].left) update(tree[no].left, le, mi, k, v);
	else{
		tree[no].left=tree.size();
		update(tree[no].left, le, mi, k, v);
	}
	if(tree[no].righ) update(tree[no].righ, mi+1, ri, k, v);
	else{
		tree[no].righ=tree.size();
		update(tree[no].righ, mi+1, ri, k, v);
	}
	
	tree[no].qt=tree[tree[no].left].qt + tree[tree[no].righ].qt;
}


int main()
{
	int n, q, u;
	scanf("%d", &n);
		
		map <int, int> m1;
		int ct1=0;
		rep(i, 0, n){
			scanf("%d", &u);
			m1[u]=ct1++;
			in[ct1-1].x=u;
		}
		
		vector <iii> qy;
		
		scanf("%d", &q);
		char op; int a, b;
		rep(i, 0, q){
			scanf(" %c", &op);
			if(op=='R') scanf("%d", &a);
			else scanf("%d %d", &a, &b);
			
			qy.pb(mp(op, mp(a, b)));
			
			if(op=='I'){
				m1[a]=ct1++;
				in[ct1-1].x=a;
				in[m1[b]].r.push_front(mp(i, ct1-1));
			}
		}
		
		map <int, priority_queue<ii> > m2; int ct2=0;
		rep(i, 0, n){
			m2[in[i].x].push(mp(1, ct2++));
			priority_queue <ii> s;
			rep(j, 0, in[i].r.size()) s.push(in[i].r[j]);
			while(!s.empty()){
				u=s.top().S, b=s.top().F; s.pop();
				m2[in[u].x].push(mp(-b, ct2++));
				rep(j, 0, in[u].r.size()) s.push(in[u].r[j]);
			}
		}
	
		/*rep(i, 0, 50){
			if(m2.count(i)){
				cout << i << " : ";
				while(!m2[i].empty()){
					cout << m2[i].top().S << " ";
					m2[i].pop();
				}
				cout << '\n';
			}
		}*/
		
		m1.clear();
		rep(i, 0, n){
			a=in[i].x;
			update(0, 0, ct2+2, m2[a].top().S, 1);
		}
		
		rep(i, 0, q){
			op=qy[i].F, a=qy[i].S.F, b=qy[i].S.S;
			if(op=='Q'){
				if(m2[a].top().S > m2[b].top().S) swap(a, b);
				printf("%d\n", max(query(0, 0, ct2+2, m2[a].top().S, m2[b].top().S)-2, -1));
			}else if(op=='I'){
				update(0, 0, ct2+2, m2[a].top().S, 1);
			}else{
				update(0, 0, ct2+2, m2[a].top().S, -1);
				m2[a].pop();
			}
		}
		
	
	return 0;
	
}
