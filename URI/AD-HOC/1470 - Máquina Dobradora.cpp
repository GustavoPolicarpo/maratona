// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Máquina Dobradora
// Nível: 6
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1470

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
int N, M;
int n[20], m[20];
set <vector <int> > ss;

bool solve(){
	
	queue < vector<int> > q;	
	rep(i, 1, N+1){
		vector <int> aux;
		int j=i, k=i-1;
		if(i<=N/2){
			while(k>=0){
				aux.pb(n[j++]+n[k--]);
			}
			while(j<N) aux.pb(n[j++]);
		}
		else{
			while(j<N){
				aux.pb(n[j++]+n[k--]);
			}
			while(k>=0) aux.pb(n[k--]);
		}
		/*rep(j, 0, aux.size()){
			cout << aux[j] << " ";
		}
		cout << endl;*/
		if(aux.size()<M) continue;
		
		if(aux.size()==M){
			bool ret=true;
			rep(j, 0, M)
				if(aux[j]!=m[j]){
					ret=false;
					break;
				}
			if(ret) return ret;
		}
		q.push(aux); ss.insert(aux);
		
		reverse(aux.begin(), aux.end());
		if(aux.size()==M){
			bool ret=true;
			rep(j, 0, M)
				if(aux[j]!=m[j]){
					ret=false;
					break;
				}
			if(ret) return ret;
		}
		q.push(aux); ss.insert(aux);
	}
	while(!q.empty()){
		vector <int> nn=q.front(); q.pop(); int tam=nn.size();
		rep(i, 1, tam){
			vector <int> aux;
			int j=i, k=i-1;
			if(i<=tam/2){
				while(k>=0){
					aux.pb(nn[j++]+nn[k--]);
				}
				while(j<tam) aux.pb(nn[j++]);
			}
			else{
				while(j<tam){
					aux.pb(nn[j++]+nn[k--]);
				}
				while(k>=0) aux.pb(nn[k--]);
			}
			/*rep(j, 0, aux.size()){
				cout << aux[j] << " ";
			}
			cout << endl;*/
			if(aux.size()<M || ss.count(aux)) continue;
			
			if(aux.size()==M){
				bool ret=true;
				rep(j, 0, M)
					if(aux[j]!=m[j]){
						ret=false;
						break;
					}
				if(ret) return ret;
			}
			q.push(aux); ss.insert(aux);
			
			reverse(aux.begin(), aux.end());
			if(aux.size()==M){
				bool ret=true;
				rep(j, 0, M)
					if(aux[j]!=m[j]){
						ret=false;
						break;
					}
				if(ret) return ret;
			}
			q.push(aux); ss.insert(aux);
		}
	}
	return false;
}
int main()
{
	//freopen("out.txt", "w", stdout);
	//freopen("in.txt", "r", stdin);
	while(scanf("%d", &N)!=EOF){ ss.clear();
		rep(i, 0, N) scanf("%d", &n[i]);
		scanf("%d", &M);
		rep(i, 0, M) scanf("%d", &m[i]);
		bool yep=solve();
		if(yep) puts("S");
		else puts("N");
	}
	
	return 0;	
}



