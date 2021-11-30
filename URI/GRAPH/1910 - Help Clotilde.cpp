// Author: Gustavo Policarpo
// Name: Help Clotilde
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1910

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
#define MAXV 100001
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
ll readInt();
int pro[100001], vis[100001];
int O, D, K, aux;

void bfs()
{
	queue <ii> q;
	q.push(mp(O, 0));
	while(!q.empty()){
		int u=q.front().F, mov=q.front().S; q.pop();
		//cout << u << endl;
		if(u==D){
			printf("%d\n", mov); return;
		}
		if(u-1>0 && !vis[u-1] && !pro[u-1]){
			vis[u-1]=1;
			q.push(mp(u-1, mov+1));
		}
		if(u+1<100001 && !vis[u+1] && !pro[u+1]){
			vis[u+1]=1;
			q.push(mp(u+1, mov+1));
		}
		if(u*2<100001 && !vis[u*2] && !pro[u*2]){
			vis[u*2]=1;
			q.push(mp(u*2, mov+1));
		}
		if(u*3<100001 && !vis[u*3] && !pro[u*3]){
			vis[u*3]=1;
			q.push(mp(u*3, mov+1));
		}
		if(u%2==0 && !vis[u/2] && !pro[u/2]){
			vis[u/2]=1;
			q.push(mp(u/2, mov+1));
		}
	}
	printf("-1\n");
}
int main()
{
	memset(pro, 0, sizeof pro); vector <int> apa;
	while(scanf("%d %d %d", &O, &D, &K) and O+D+K){
		memset(vis, 0, sizeof vis);
		rep(i, 0, apa.size()) pro[apa[i]]=0; apa.clear();
		rep(i, 0, K){
			aux=readInt();
			pro[aux]=1; apa.pb(aux);
		}
		bfs();
	}

return 0;
}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}
