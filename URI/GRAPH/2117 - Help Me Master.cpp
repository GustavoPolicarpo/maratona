// Author: Gustavo Policarpo
// Name: Help Me Master
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2117

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

vector <int> adj[10015];
int match[10015];
int vis[10015];
int let[10010][30];

int aug(int v)
{
    if(vis[v]==1) return 0;
    vis[v]=1;
    rep(i, 0, adj[v].size()){
        int u=adj[v][i];
        if(match[u]==-1 || aug(match[u])){
            match[u]=v;
            return 1;
        }
    }
    return 0;
}


int main()
{
    memset(match, -1, sizeof(match));
    memset(let, 0, sizeof(let));
    
    int N, M; 
	
	scanf("%d %d ", &N, &M);
    string aux; 
    rep(i, 0, N){
        getline(cin, aux);
        rep(j, 0, aux.size()){
            char l=toupper(aux[j]);
            if(isalpha(l))
            	let[i][l-'A']++;
        }       
    }
    
    char letra; int num;
    rep(i, 0, M){
        scanf(" %c %d",&letra,&num);
        letra = toupper(letra);
    	rep(j, 0, N){
            if(let[j][letra-'A']>=num)
                adj[j].pb(i+N); //comentario i liga na pessoa j
        }
    }  //N e o numero de comentarios, M o de pessoas
    int mcbm=0;
    
    rep(i, 0, N){ //mcbm de todos os comentarios
        rep(j, 0, N)
            vis[j]=0;
        mcbm+=aug(i);
    }
    cout << mcbm << "\n";
    
return 0;
}

