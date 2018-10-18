// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Circo das Pulgas
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2529

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)

typedef struct node{
    int prior,size;
    int val;//value stored in the array
    int sum;//whatever info you want to maintain in segtree for each node
    int lazy;//whatever lazy update you want to do
    int rev;
    struct node *l,*r;
}node;
typedef node* pnode;
int sz(pnode t){
    return t?t->size:0;
}
void upd_sz(pnode t){
    if(t)t->size=sz(t->l)+1+sz(t->r);
}
void lazy(pnode t){
    if(!t || t->lazy==-1)return;
    t->val=t->lazy;//operation of lazy
    t->sum=t->lazy*sz(t);
    if(t->l)t->l->lazy=t->lazy;//propagate lazy
    if(t->r)t->r->lazy=t->lazy;
    t->lazy=-1;
}
void reset(pnode t){
    if(t)t->sum = t->val;//no need to reset lazy coz when we call this lazy would itself be propagated
}
void combine(pnode& t,pnode l,pnode r){//combining two ranges of segtree
    if(!l || !r)return void(t = l?l:r);
    t->sum = l->sum + r->sum;
}
void operation(pnode t){//operation of segtree
    if(!t)return;
    reset(t);//reset the value of current node assuming it now represents a single element of the array
    lazy(t->l);lazy(t->r);//imp:propagate lazy before combining t->l,t->r;
    combine(t,t->l,t);
    combine(t,t,t->r);
}
void push(pnode t){
	if(!t || !t->rev) return;
	t->rev=false;
	swap(t->l, t->r);
	if(t->l)  t->l->rev ^= true;
    if(t->r)  t->r->rev ^= true;
}
void split(pnode t,pnode &l,pnode &r,int pos,int add=0){
    if(!t)return void(l=r=NULL);
    push(t); lazy(t); 
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)//element at pos goes to left subtree(l)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else 
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}
void merge(pnode &t,pnode l,pnode r){ //l->leftarray,r->rightarray,t->resulting array
    push(l);push(r);lazy(l);lazy(r);
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
    ret->sum=val;ret->lazy=-1; ret->rev=0;
    ret->l=NULL, ret->r=NULL;
    return ret;
}
int range_query(pnode t,int l,int r){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    int ans = t->sum;
    merge(mid,L,t);
    merge(t,mid,R);
    return ans;
}
void range_update(pnode t,int l,int r,int val){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);//note: r-l!!
    t->lazy=val; //lazy_update
    merge(mid,L,t);
    merge(t,mid,R);
}
void reverse(pnode t, int l, int r){
	pnode L, mid, R;
	split(t, L, mid, l-1);
	split(mid, mid, R, r-l);
	mid->rev^=true;
	merge(t, L, mid);
	merge(t, t, R);
}
void output(pnode t) {
    if (!t)  return;
    push (t);
    lazy(t);
    output (t->l);
    printf ("%d ", t->val);
    output (t->r);
}

int valor(int val){
	return val&1?0:1;
}

int main(){
	
	int P, Q;
	
	while(scanf("%d %d", &P, &Q) !=EOF){
		pnode tree=NULL, T1=NULL, T2=NULL, T3=NULL; int val;
		
		rep(i, 0, P){
			scanf("%d", &val);
			split(tree, T1, T2, i);
			merge(T1, T1, init(valor(val)));
			merge(tree, T1, T2);
		}
		
		char op; int a, b;
		while(Q--){
			scanf(" %c %d %d", &op, &a, &b);
			
			if(op=='S') range_update(tree, a-1, a-1, valor(b));
			
			else if(op=='I') reverse(tree, a-1, b-1);
			
			else{
				int ans=range_query(tree, a-1, b-1);
				if(op=='E') printf("%d\n", ans);
				else printf("%d\n", b-a+1-ans);
			}
			
		}
		
	}
	
	return 0;
	
}

