// Author: Gustavo Policarpo
// Name: Bino, Prant and Indecision
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2186

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
    char val1;
    int qt[26];
    //map<char, int> qt;
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

void reset(pnode t){
	rep(i, 0, 26) t->qt[i] = 0;
    t->qt[t->val1] = 1;
}
void combine(pnode& t,pnode l,pnode r){
    if(!l || !r)return void(t = l?l:r);
    rep(i, 0, 26){
    	t->qt[i] = l->qt[i] + r->qt[i];
	}
}
void operation(pnode t){
    if(!t)return;
    reset(t);
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
    push(t); 
    int curr_pos = add + sz(t->l);
    if(curr_pos<=pos)
        split(t->r,t->r,r,pos,curr_pos+1),l=t;
    else 
        split(t->l,l,t->l,pos,add),r=t;
    upd_sz(t);
    operation(t);
}

void merge(pnode &t,pnode l,pnode r){ 
    push(l);push(r);
    if(!l || !r) t = l?l:r;
    else if(l->prior>r->prior)merge(l->r,l->r,r),t=l;
    else    merge(r->l,l,r->l),t=r;
    upd_sz(t);
    operation(t);
}

int range_query1(pnode t,int l,int r, char c){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    int ans = t->qt[c];
    merge(mid,L,t);
    merge(t,mid,R);
    return ans;
}

void output(pnode t) {
    if (!t)  return;
    push (t);
    output (t->l);
    printf("%c", char(t->val1+'a'));
    output (t->r);
}

int acheisol;
void sol1(pnode t, int &ans, int c){
	if(!t || t->qt[c]==0) return;
	push(t);
	if(t->l && t->l->qt[c]>=1) sol1(t->l, ans, c);
	else if(t->val1==c){
		acheisol = 1;
		ans += sz(t->l);
		return;
	}
	else if(t->r && t->r->qt[c]>=1){
		ans = ans+sz(t->l)+1;
		sol1(t->r, ans, c);
	}
}

void sol2(pnode t, int &ans, int c){
	if(!t || t->qt[c]==0) return;
	push(t);
	if(t->r && t->r->qt[c]>=1) sol2(t->r, ans, c);
	else if(t->val1==c){
		ans += sz(t->r);
		return;
	}
	else if(t->l && t->l->qt[c]>=1){
		ans = ans+sz(t->r)+1;
		sol2(t->l, ans, c);
	} 
}

ii range_query2(pnode t,int l,int r, int c){//[l,r]
    pnode L,mid,R;
    split(t,L,mid,l-1);
    split(mid,t,R,r-l);
    ii ans = ii(0, 0); acheisol = 0;
    sol1(t, ans.F, c);
    if(!acheisol){
    	merge(mid,L,t);
    	merge(t,mid,R);
    	return ii(-1, -1);
	}
    sol2(t, ans.S, c);
    ans.F = ans.F + l + 1, ans.S = r-ans.S+1;
    merge(mid,L,t);
    merge(t,mid,R);
    return ans;
}

void reverse(pnode t, int l, int r){
	pnode L, mid, R;
	split(t, L, mid, l-1);
	split(mid, mid, R, r-l);
	mid->rev^=true;
	merge(t, L, mid);
	merge(t, t, R);
}

pnode init(int val){
    pnode ret = new node;
    ret->prior=rand();ret->size=1;
    ret->val1=val;
    reset(ret);
    ret->rev=0;
    ret->l=NULL, ret->r=NULL;
    return ret;
}

int L, N;
char s[1000010];
pnode tree=NULL, T1=NULL, T2=NULL, T3=NULL; 

int valor(char c){
	return int(c-'a');
}
int main()
{
	
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

	scanf("%d %d", &L, &N);
	gets(s);
	gets(s);

	rep(i, 0, L){
		//split(tree, T1, T2, i);
		//merge(T1, T1, init(s[i], i));
		merge(tree, tree, init(valor(s[i])));
	}
	
	//output(tree);
//	cout << '\n';
	//cout << "here\n";
	int op, a, b; char c;
	while(N--){
		scanf("%d", &op);
		if(op==1){
			scanf("%d %d %c", &a, &b, &c);
			if(a>b) swap(a, b);
			printf("%d\n", range_query1(tree, a-1, b-1, valor(c)));
		}
		if(op==2){
			scanf("%d %d %c", &a, &b, &c);
			if(a>b) swap(a, b);
			ii ans = range_query2(tree, a-1, b-1, valor(c));
			if(ans.S==-1) puts("-1");
			else printf("%d %d\n", ans.F, ans.S);
		}
		if(op==3){
			scanf("%d %d", &a, &b);
			if(a>b) swap(a, b);
			reverse(tree, a-1, b-1);
		}
		if(op==4){
			scanf("%d %c", &a, &c);
			split(tree, T1, T2, a-2);
			merge(T1, T1, init(valor(c)));
			merge(tree, T1, T2);
		}
		
		/*output(tree);
		cout << '\n';
		output2(tree);
		puts("");*/
	}
	
	output(tree); puts("");
	
	
	
	return 0;
	
}
