// Author: Gustavo Policarpo
// Name: Letters
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1714

#define gc getchar_unlocked
#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

int N, dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0}, vis[101][101], cango[10];
char mat[101][101];

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<N && y<N;
}
int bfs(){
	queue <iii> q; iii aux;
	aux.F.F=0, aux.F.S=0, aux.S=0; vis[0][0]=1;
	if(isupper(mat[aux.F.F][aux.F.S])){
		if(cango[mat[aux.F.F][aux.F.S]-'A']==1) q.push(aux);
	}
	else{
		if(cango[mat[aux.F.F][aux.F.S]-'a']==0) q.push(aux);
	}
	while(!q.empty()){
		aux=q.front(); q.pop();
		//cout << aux.F.F << " " << aux.F.S << " " << aux.S << endl;
		//if(vis[aux.F.F][aux.F.S]) continue;
		if(aux.F.F==N-1 && aux.F.S==N-1) return aux.S+1;
		
		rep(i, 0, 4){
			iii go;
			go.F.F=aux.F.F+dx[i], go.F.S=aux.F.S+dy[i], go.S=aux.S+1;
			if(!dentro(go.F.F, go.F.S) || vis[go.F.F][go.F.S]) continue;
			vis[go.F.F][go.F.S]=1;
			if(isupper(mat[go.F.F][go.F.S])){
				if(cango[mat[go.F.F][go.F.S]-'A']==1) q.push(go);
			}
			else{
				if(cango[mat[go.F.F][go.F.S]-'a']==0) q.push(go);
			}
		}
	}
	
	return INF;
}
int main()
{
	//freopen("out.txt", "w", stdout);
	//freopen("in.txt", "r", stdin);
	
	
	scanf("%d", &N); char s[N];
	rep(i, 0, N){
		scanf("%s", s);
		rep(j, 0, N){
			mat[i][j]=s[j];
		}
	}
	
	int ans=INF;
	rep(a, 0, 2)
	rep(b, 0, 2)
	rep(c, 0, 2)
	rep(d, 0, 2)
	rep(e, 0, 2)
	rep(f, 0, 2)
	rep(g, 0, 2)
	rep(h, 0, 2)
	rep(i, 0, 2)
	rep(j, 0, 2){
		cango[0]=a, cango[1]=b, cango[2]=c, cango[3]=d, cango[4]=e,
		cango[5]=f, cango[6]=g, cango[7]=h, cango[8]=i, cango[9]=j;
		memset(vis, 0, sizeof vis);
		ans=min(ans, bfs());
	}
	if(ans>=INF) printf("-1\n");
	else printf("%d\n", ans);
	return 0;	
}

/*
DdaAaA
CBAcca
eEaeeE
bBbabB
DbDbDc
fFaAaC
*/


