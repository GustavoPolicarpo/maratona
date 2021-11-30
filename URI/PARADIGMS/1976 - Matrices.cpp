// Author: Gustavo Policarpo
// Name: Matrices
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1976

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

const ll INF = 1LL<<50;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct matriz{
	int l, c;
}; int N, memo[1010][1010], moreone[1010][1010]; ll pd[1010][1010]; matriz n[1010];
bool twice;

ll solve(int i, int j){
	
	if(i==j) return 0;
	
	if(pd[i][j]!=-1) return pd[i][j];
	
	ll ret=INF;
	
	bool yep=false;
	rep(k, i, j){
		ll aux=solve(i, k) + solve(k+1, j) + n[i].l*n[k].c*n[j].c;
		if(ret>aux){
			ret=aux;
			memo[i][j]=k;
			yep=false;
		}
		else if(ret==aux) yep=true;
	}
	
	if(yep) twice=true;
	
	return pd[i][j]=ret;
	
}

void take_parenteses(int i, int j, vector <char> &v)  
{  

    if (i == j){  
		printf("A%d", i+1);
        /*v.pb('A');
        string push; int aux=i+1;
        while(aux){
        	push+=aux%10+'0';
        	aux/=10;
		}
		
		for(int p=push.size()-1; p>=0; p--) 
			v.pb(push[p]);*/

        return;
    }  
 
    int k = memo[i][j]; 
      
    printf("(");
    //v.pb('(');

    take_parenteses(i, k, v);  

	take_parenteses(k + 1, j, v);  

    printf(")"); 
    //v.pb(')');
	 
	return ;
}

int main()
{
	
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &N) and N){
		
		rep(i, 0, N){
			scanint(n[i].l), scanint(n[i].c);
			rep(j, i, N) pd[i][j]=-1;
		}	pd[N][N]=-1;
		
		twice=false;
		ll ans=solve(0, N-1);
		
		if(twice) printf("%lld\n", ans);
		else{
			vector <char> out;
			take_parenteses(0, N-1, out);
			
			rep(i, 0, out.size())
				printf("%c", out[i]);
			printf("\n");
		}
		
	}

	return 0;
	
}
