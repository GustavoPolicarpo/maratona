// Author: Gustavo Policarpo
// Name: Gluing Pictures
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3018

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;
const int MAX = 2e5+5;
int RA[MAX], tempRA[MAX];
int SA[MAX], tempSA[MAX];
int PLCP[MAX], LCP[MAX];
int c[MAX], Phi[MAX];
char T[MAX];
char t[MAX];
ll n;
int ti;
vector <string> vs;
int beg[MAX];
int q;
int fromL[MAX], fromR[MAX];
int mapR[MAX];


void countingSort(int k) {
	int i, sum, maxi = max((ll)300, n);
	memset(c, 0, sizeof c);
	for(i = 0; i < n; i++) c[i+k<n ? RA[i+k] : 0]++;
	for(i = sum = 0; i < maxi; i++) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for(i = 0; i < n; i++)
		tempSA[c[SA[i] + k < n ? RA[SA[i]+k] : 0]++] = SA[i];
	for(i = 0; i < n; i++) SA[i] = tempSA[i];
}

void constructSA() {
	int i, k, r;
	for(i = 0; i < n; i++) RA[i] = T[i];
	for(i = 0; i < n; i++) SA[i] = i;
	for(k = 1; k < n; k <<= 1) {
		countingSort(k);
		countingSort(0);
		tempRA[SA[0]] = r = 0;
		for(i = 1; i < n; i++)
			tempRA[SA[i]] = (RA[SA[i]] == RA[SA[i-1]] && RA[SA[i]+k] == RA[SA[i-1]+k]) ? r : ++r;
		for(i = 0; i < n; i++) RA[i] = tempRA[i];
		if(RA[SA[n-1]] == n-1) break;
	}
}

void computeLCP() {
	int i, L;
	Phi[SA[0]] = -1;
	for(i = 1; i < n; i++) Phi[SA[i]] = SA[i-1];
	for(i = L = 0; i < n; i++) {
		if(Phi[i] == -1) {
			PLCP[i] = 0;
			continue;
		}
		while(T[i+L] == T[Phi[i]+L]) L++;
		PLCP[i] = L;
		L = max(L-1, 0);
	}
	for(i = 0; i < n; i++)
		LCP[i] = PLCP[SA[i]];
}

void propL(){
	int at = 0;
	for(int i=n-1; i>=0; i--){
		fromL[i] = at;
		if(SA[i]<ti){
			at = LCP[i];
		}else{
			at = min(at, LCP[i]);
		}
	}
}

void propR(){
	int at = 0;
	for(int i=0; i<n; i++){
		if(SA[i]<ti){
			at = LCP[i+1];
		}else{
			at = min(at, LCP[i+1]);
		}
		fromR[i+1] = at;
	}
}


void printAll(char s[]) {
	printf("SA\ttam\tLCP\tSuffix\n");
	rep(i, 0, n) printf("%2d\t%2d\t%2d\t%s\n", SA[i], n-SA[i], LCP[i], s + SA[i]);
}

int main(){
	
	scanf("%s", T);
	n = strlen(T);
	T[n++] = '#';
	ti = n;
	
	scanf("%d", &q);
	rep(i, 0, q){
		beg[i] = n;
		scanf("%s", t);
		int tt = strlen(t);
		rep(j, 0, tt){
			T[n++] = t[j];
		}
		vs.pb(t);
	}
	T[n++] = '$';
	
	//cout << T << "\n";
	
	constructSA();
	computeLCP();
	//printAll(T);
	
	
	rep(i, 0, n){
		mapR[SA[i]] = i;
	}
	
	propL();
	propR();
	
	
	rep(i, 0, q){
		int pos = beg[i], sz = 0, ans = 0;
		while(sz<vs[i].size()){
			//debug(pos);
			int tk = mapR[pos];
			int go = max(fromL[tk], fromR[tk]);
			//debug2(tk, go);
			if(go==0){
				sz = -1;
				break;
			}
			sz+=go;
			pos+=go;
			ans++;
		}
		if(sz==-1) ans = -1;
		printf("%d\n", ans);
	}
	
		
	return 0;
}
