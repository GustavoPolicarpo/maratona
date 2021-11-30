// Author: Gustavo Policarpo
// Name: Go up the "Ultras"
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1496

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

int N, h[100010];
int tree1[400040], tree2[400040];

void build(int no, int i, int j){
	if(i==j){
		tree1[no] = h[i];
		tree2[no] = h[i];
		return;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	tree1[no] = max(tree1[L], tree1[R]);
	tree2[no] = min(tree2[L], tree2[R]);
}

int query1(int no, int i, int j, int a, int b, int k){
	if(i>j || i>b || j<a || tree1[no]<=k) return -1;
	if(i==j) return i;
	int L = no*2, R = L+1, mid = (i+j)/2;
	int SR = query1(R, mid+1, j, a, b, k);
	if(SR!=-1) return SR;
	int SL = query1(L, i, mid, a, b, k);
	return SL;
}

int query2(int no, int i, int j, int a, int b, int k){
	if(i>j || i>b || j<a || tree1[no]<=k) return -1;
	if(i==j) return i;
	int L = no*2, R = L+1, mid = (i+j)/2;
	int SL = query2(L, i, mid, a, b, k);
	if(SL!=-1) return SL;
	int SR = query2(R, mid+1, j, a, b, k);
	return SR;
}

int query3(int no, int i, int j, int a, int b){
	if(i>j || i>b || j<a) return 0x3f3f3f3f;
	if(i>=a && j<=b) return tree2[no];
	int L = no*2, R = L+1, mid = (i+j)/2;
	int SL = query3(L, i, mid, a, b);
	int SR = query3(R, mid+1, j, a, b);
	return min(SL, SR);
}

int main(){

	while(scanf("%d", &N)!=EOF){
		rep(i, 0, N) scanf("%d", &h[i]);
		build(1, 0, N-1); int yep = 0;
		rep(i, 1, N-1){
			int idl = query1(1, 0, N-1, 0, i-1, h[i]);
			int idr = query2(1, 0, N-1, i+1, N-1, h[i]);
			int mhl = 0, mhr = 0;
			if(idl!=-1) mhl = query3(1, 0, N-1, idl+1, i);
			if(idr!=-1) mhr = query3(1, 0, N-1, i, idr-1);
			int p = h[i] - max(mhl, mhr);
			if(p>=150000){
				if(yep) printf(" ");
				yep = 1; printf("%d", i+1);
			}
		}	printf("\n");
	}
	
	
	return 0;
}
