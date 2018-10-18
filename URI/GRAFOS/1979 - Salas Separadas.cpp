// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Salas Separadas
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1979

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < ll, ll > ii;

vector <int> adj[102];
int cor[102];

bool did=true;

bool bfsc(int u, int c)
{
	queue <ii> q;
	q.push(mp( u, c));
	cor[u]=c;
	while(!q.empty()){
		u=q.front().first;
		c=q.front().second;
		//cout << u << " " << c << endl;
		q.pop();
		cor[u]=c;
		rep(i, 0, adj[u].size()){
			int w=adj[u][i];
			if(cor[w]==c){
				return false;
				break;
			}
			if(cor[w]==0)
				q.push(mp(w, c*-1));
		}
	}
	return true;	
}


void tozero(int n)
{
	rep(i, 0, n+1){
		adj[i].clear();
		cor[i]=0;
	}
}

int main()
{
	int N;
	while(cin >> N && N){
		tozero(N);
		int bk=N;
		while(N--){
			int x; cin >> x;
			cin.ignore();
			string temp; getline(cin, temp);
			vector <int> f; int aux=0;
			rep(i, 0, temp.size()){
				if(isspace(temp[i])){
					f.pb(aux);
					aux=0;
				}
				else{
					aux*=10;
					aux+=temp[i]-'0';
				}
			}
			f.pb(aux);
			rep(i, 0, f.size())
				adj[x].pb(f[i]);
				
			f.clear();		
		}
				
		
		bool yep=bfsc(1, 1);
		if(yep)
			cout << "SIM";
		else
			cout << "NAO";
		cout << endl;
	}


return (0);
}
