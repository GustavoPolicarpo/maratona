// Author: Gustavo Policarpo
// Name: Is it Ordered?
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1740

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

typedef struct node{
    int prior,size;
    int val, menor, maior;
    bool c, d, e;
    struct node *l,*r;
}node;

typedef node* pnode;
int sz(pnode t){
    return t?t->size:0;	
}
void upd_sz(pnode &t){
    if(t)t->size=sz(t->l)+1+sz(t->r);
}
void reset(pnode &t){
	t->menor = t->maior = t->val;
	t->c = t->d = t->e = true;
}
void combine(pnode& t,pnode l,pnode r){
    if(!l || !r)return void(t = l?l:r);
    if(l->e && r->e && t->val==l->menor && t->val==r->maior) t->e=true;
    else t->e = false;
    if(l->c && r->c && t->val>=l->maior && t->val<=r->menor) t->c=true;
    else t->c = false;
    if(l->d && r->d && t->val<=l->menor && t->val>=r->maior) t->d=true;
    else t->d = false;
    t->maior = max(l->maior, r->maior);
    t->menor = min(l->menor, r->menor);
}
void operation(pnode t){
    if(!t)return;
    reset(t);
    combine(t,t->l,t);
    combine(t,t,t->r);
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else 
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){ 
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else    merge(r->l,l,r->l),t=r;
    upd_sz(t);
    operation(t);
}
pnode init(int val){
    pnode ret = new node;
    ret->prior=rand();ret->size=1;
    ret->val=val;
    reset(ret);
    ret->l=NULL, ret->r=NULL;
    return ret;
}
int valor(int n){
	return int(n - 0);
}
void output(pnode &t) {
    if (!t)  return;
    output (t->l);
    printf("%d ", t->val);
    output (t->r);
}
int value(pnode &t, int x){
	pnode L, mid, R;
	split(t, L, mid, x-1);
	split(mid, t, R, 0);
	int ret = t->val;
	merge(mid, L, t);
	merge(t, mid, R);
	return ret;
}
void update(pnode &t, int x, int val){
	pnode L, mid, R;
	split(t, L, mid, x-1);
	split(mid, t, R, 0);
	t->val = val;
	merge(mid, L, t);
	merge(t, mid, R);
}
void insert(pnode &t, int x, int val){
	pnode L, R;
	split(t, L, R, x-1);
	merge(t, L, init(valor(val)));
	merge(t, t, R);
}
void erase(pnode &t, int x){
	pnode L, mid, R;
	split(t, L, mid, x-1);
	split(mid, t, R, 0);
	merge(t, L, R);
}
void query(pnode &t, int x, int y){
	pnode L, mid, R;
	split(t, L, mid, x-1);
	split(mid, t, R, y-x);
	if(t->e) puts("ALL EQUAL");
	else if(t->c) puts("NON DECREASING");
	else if(t->d) puts("NON INCREASING");
	else puts("NONE");
	merge(mid, L, t);
	merge(t, mid, R);
}

int N, aux, Q;
int op, x, y;

int main()
{
	
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

	
	while(scanf("%d", &N)!=EOF){
		pnode tree = NULL;
		
		rep(i, 0, N){
			scanf("%d", &aux);
			merge(tree, tree, init(valor(aux)));
		}
		
		scanf("%d", &Q);
		while(Q--){
			scanf("%d", &op);
			if(op==0){
				scanf("%d %d", &x, &y); x--, y--;
				int valx = value(tree, x);
				int valy = value(tree, y);
				update(tree, x, valy);
				update(tree, y, valx);
			}
			if(op==1){
				scanf("%d %d", &x, &y); x--;
				update(tree, x, y);
			}
			if(op==2){
				scanf("%d %d", &x, &y); x--;
				insert(tree, x, y);
			}
			if(op==3){
				scanf("%d", &x); x--;
				erase(tree, x);
			}
			if(op==4){
				scanf("%d %d", &x, &y); x--, y--; if(x>y) swap(x, y);
				query(tree, x, y);
			}
			
			//output(tree); puts("");
		}
	}
	
	return 0;
	
}
