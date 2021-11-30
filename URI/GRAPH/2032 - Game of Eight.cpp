// Author: Gustavo Policarpo
// Name: Game of Eight
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2032

//#define gc getchar_unlocked
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

//freopen("in.txt", "r", stdin);
//

vector <int> in, fim;
vector < vector<int> > ans, ret;
set <vector <int> > s;

struct game{
	int c, id;
	vector <int> atual;
};

int pai[10000010];

int cnt=0;

int bfs(){
	queue <game> q; game aux;
	aux.c=0, aux.atual=in, aux.id=cnt++; s.insert(in);
	q.push(aux);
	while(!q.empty()){
		game u=q.front(); q.pop();
	
		ret.pb(u.atual);
			
		if(u.atual==fim){
			int v=u.id;
			ans.pb(u.atual);
			while(pai[v]!=0){
				v=pai[v];
				ans.pb(ret[v]);
			}
			return u.c;
		}
		aux.atual=u.atual, aux.c=u.c+1;
		if(u.atual[0]==0){
			swap(aux.atual[0], aux.atual[3]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[0], aux.atual[3]),
			swap(aux.atual[0], aux.atual[1]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);	
		}
		
		else if(u.atual[1]==0){	
			swap(aux.atual[1], aux.atual[4]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[1], aux.atual[4]),
			swap(aux.atual[1], aux.atual[2]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[1], aux.atual[2]),
			swap(aux.atual[0], aux.atual[1]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);	
		}
		
		else if(u.atual[2]==0){		
			swap(aux.atual[2], aux.atual[5]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[2], aux.atual[5]),
			swap(aux.atual[1], aux.atual[2]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);			
		}
		
		else if(u.atual[3]==0){
			swap(aux.atual[0], aux.atual[3]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[0], aux.atual[3]),
			swap(aux.atual[3], aux.atual[6]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[3], aux.atual[6]),
			swap(aux.atual[3], aux.atual[4]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);		
		}
		
		else if(u.atual[4]==0){
			swap(aux.atual[1], aux.atual[4]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[1], aux.atual[4]),
			swap(aux.atual[4], aux.atual[7]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[4], aux.atual[7]),
			swap(aux.atual[4], aux.atual[5]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[4], aux.atual[5]),
			swap(aux.atual[3], aux.atual[4]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id,  s.insert(aux.atual), q.push(aux);		
		}
		
		else if(u.atual[5]==0){
			swap(aux.atual[2], aux.atual[5]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[2], aux.atual[5]),
			swap(aux.atual[5], aux.atual[8]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[5], aux.atual[8]),
			swap(aux.atual[4], aux.atual[5]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);		
		}
		
		else if(u.atual[6]==0){
			swap(aux.atual[3], aux.atual[6]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[3], aux.atual[6]),
			swap(aux.atual[6], aux.atual[7]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);	
		}	
		
		else if(u.atual[7]==0){
			swap(aux.atual[4], aux.atual[7]);
			if(!s.count(aux.atual))pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[4], aux.atual[7]),
			swap(aux.atual[7], aux.atual[8]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[7], aux.atual[8]),
			swap(aux.atual[6], aux.atual[7]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);		
		}
		
		else if(u.atual[8]==0){
			swap(aux.atual[5], aux.atual[8]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);
			
			swap(aux.atual[5], aux.atual[8]),
			swap(aux.atual[7], aux.atual[8]);
			if(!s.count(aux.atual)) pai[aux.id=cnt++]=u.id, s.insert(aux.atual), q.push(aux);		
		}
	}
	return -1;
}

int main()
{
	//freopen("out.txt", "w", stdout);
	rep(i, 1, 9) fim.pb(i); fim.pb(0);
	string n;
	while(cin >> n){
		rep(i, 0, 3) in.pb(n[i]-'0');
		cin >> n;
		rep(i, 0, 3) in.pb(n[i]-'0');
		cin >> n;
		rep(i, 0, 3) in.pb(n[i]-'0');
		int out=bfs();
		if(out==-1) puts("Problema sem solucao");
		else{
			printf("Quantidade minima de passos = %d\n", out);
			for(int i=ans.size()-1; i>=0; i--){
				if(i<ans.size()-1) printf("\n");
				rep(j, 0, 3){
					rep(k, 0, 3){
						printf("%d", ans[i][j*3+k]);
					}
					printf("\n");
				}
			}
		}
		s.clear(), ret.clear(), ans.clear(), in.clear(); cnt=0;
		
	}
	
return 0;
}
