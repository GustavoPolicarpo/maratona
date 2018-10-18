// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Número de Erdos
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2249

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
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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
//freopen("out.txt", "w", stdout);

int N;

vector <int> adj[1001];
map<string, int> mapa;
map<string, int> ans;
map<int, string> ret;

int vis[1001];

void bfs(int u){
	queue <ii> q;
	q.push(mp(u, 0)); vis[u]=0; ans[ret[u]]=0;
	while(!q.empty()){
		int u=q.front().F, c=q.front().S; q.pop();
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v]==INF){
				vis[v]=c+1;
				ans[ret[v]]=vis[v];
				q.push(mp(v, c+1));
			}
		}
	}
	return;
}

bool comp(string a, string b){
	string aa="", bb="";
	rep(i, 3, a.size()) aa+=a[i];
	rep(i, 3, b.size()) bb+=b[i];
	if(aa>bb) return false;
	if(bb>aa) return true;
	if(a[0]>b[0]) return false;
	return true;
}
int main()
{
	string in; int z=1;
	memset(vis, INF, sizeof vis);
	while(cin >> N){
		if(!N) break;
		cin.ignore();
		vector <string> out; int cnt=1;
		
		rep(i, 0, N){
			getline(cin, in); vector <int> lig;
			string aux="";
			rep(j, 0, in.size()-1){
				if(in[j]==','){
					if(!mapa.count(aux)){
						out.pb(aux), 
						ret[cnt]=aux;
						mapa[aux]=cnt++;	
					}
					//cout << aux << endl;
					lig.pb(mapa[aux]);
					aux=""; j++;
				}
				else aux+=in[j];
			}
			if(!mapa.count(aux)){
				out.pb(aux), 
				ret[cnt]=aux;
				mapa[aux]=cnt++;	
			}
			//cout << aux << endl;
			lig.pb(mapa[aux]);
			
			rep(j, 0, lig.size()){
				rep(k, j+1, lig.size()){
					adj[lig[j]].pb(lig[k]), adj[lig[k]].pb(lig[j]);
					//cout << lig[j] << " " << lig[k] << endl;
				}
			}
		}
		
		bfs(mapa["P. Erdos"]);
		sort(out.begin(), out.end(), comp);
		
		printf("Teste %d\n", z++);
		rep(i, 0, out.size()){
			if(out[i]=="P. Erdos") continue;
			cout << out[i] << ": ";
			if(!ans.count(out[i])) cout << "infinito\n";
			else cout << ans[out[i]] << '\n';
		}
		cout << '\n';
		mapa.clear(), ans.clear(), ret.clear();
		rep(i, 0, cnt) adj[i].clear(), vis[i]=INF;
	}



return 0;
}
