// Author: Gustavo Policarpo
// Name: Regatta of Scientists
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1370

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 999999999.99
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

ii obs[160][2];
vector <iii> adj[350];
double ds[350];
double dijkstra(int x, int y, int d)
{
	rep(i, 0, d+2) ds[i]=INF;
	ds[x]=0.0;
	
	priority_queue < iii > pq;
	pq.push(mp(ds[x], x));
	
	while(!pq.empty()){
		int u=pq.top().S; double d=-pq.top().F;
		pq.pop();
		if(d!=ds[u]) continue;
		if(u==y) break;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].S;
			double c=adj[u][i].F;
			if(ds[v]>ds[u]+c){
				ds[v]=ds[u]+c;
				pq.push(mp(-ds[v],v));
			}
		}
	}
	return ds[y];
}

// k : ponto inicial da reta 1                                            
// l : ponto final da reta 1                                              
// m : ponto inicial da reta 2                                            
// n : ponto final da reta 2                                              
bool intersec2d(ii k, ii l, ii m, ii n, double &s, double &t)
{   	   
    double det;
    det = (n.F - m.F) * (l.S - k.S)  -  (n.S - m.S) * (l.F - k.F);
	if (det == 0) return false; // nao ha intersecao     
	
    s = ((n.F - m.F) * (m.S - k.S) - (n.S - m.S) * (m.F - k.F))/ det ;
    t = ((l.F - k.F) * (m.S - k.S) - (l.S - k.S) * (m.F - k.F))/ det ;
    
    return true; // ha intersecao
}
bool precalc(ii k, ii l, ii m, ii n)
{
    double s,t;
    if (!intersec2d(k, l, m, n, s, t)) return false;
    if ((s < 0) || (s>1) || (t<0) || (t>1) ) return false;
    return true;
}

double dist(ii k, ii l)
{
	double ret=sqrt( (k.F-l.F)*(k.F-l.F)+(k.S-l.S)*(k.S-l.S) );
	return ret;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int xi, xf, yi, yf, n;
	ii ini, fim;
	cout << fixed << setprecision(2);
	while(cin>>xi>>yi>>xf>>yf>>n){
		if(xi==0&&xf==0&&yi==0&&yf==0&&n==0) break;
		
		//cin>>xi>>yi>>xf>>yf>>n;
		rep(i, 0, n*2+3) adj[i].clear();
		
		ini=mp(xi,yi); fim=mp(xf, yf);
		
		rep(i, 1, n+1){
			scanf("%d %d %d %d", &xi, &yi, &xf, &yf);
			obs[i][0]=mp(xi, yi);
			obs[i][1]=mp(xf, yf);		
		}
		
		//INICIO PARA O FIM
		bool direct=true;
		rep(i, 1, n+1)
			if(precalc(ini, fim, obs[i][0], obs[i][1])){  //se houver ligação direta ja pode dar resposta
				direct=false;
				break;
			}
		if(direct){
			double menor_dist=dist(ini, fim);
			cout << menor_dist << endl;
			continue;
		}
		
		//INICIO PARA TODOS
		int aux;
		double d;
		rep(j, 1, n+1){  //ligo o inicio a todos que der
		
			aux=1;
			rep(k, 1, n+1){
				if(j==k) continue;
				if(precalc(ini, obs[j][0], obs[k][0], obs[k][1])){
					aux=0;
					break;
				}
			}
			if(aux){
				adj[0].pb(mp(dist(ini, obs[j][0]),j*2-1));
			}
			
			aux=1;
			rep(k, 1, n+1){
				if(j==k) continue;
				if(precalc(ini, obs[j][1], obs[k][0], obs[k][1])){
					aux=0;
					break;
				}
			}
			if(aux){
				adj[0].pb(mp(dist(ini, obs[j][1]),j*2));
			}	
		}
		//TODOS PARA O FIM
		rep(j, 1, n+1){  //ligo todos que der ao fim
		
			aux=1;
			rep(k, 1, n+1){
				if(j==k) continue;
				if(precalc(obs[j][0], fim, obs[k][0], obs[k][1])){
					aux=0;
					break;
				}
			}
			if(aux){
				adj[j*2-1].pb(mp(dist(fim, obs[j][0]),n*2+1));
			}
			
			aux=1;
			rep(k, 1, n+1){
				if(j==k) continue;
				if(precalc(obs[j][1], fim, obs[k][0], obs[k][1])){
					aux=0;
					break;
				}
			}
			if(aux){
				adj[j*2].pb(mp(dist(fim, obs[j][1]),n*2+1));
			}	
		}
		//TODOS PARA COM TODOS
		rep(i, 1, n+1){  //i e o 'vertice' de partida
			rep(j, i+1, n+1){	//j e o 'vertice' de chegada
			
				aux=1;
				rep(k, 1, n+1){
					if(j==k||i==k) continue;
					if(precalc(obs[i][0], obs[j][0], obs[k][0], obs[k][1])){ //tento ligar o começo do obstaculo i
						aux=0;				//ao começo do obstaculo j
						break;
					}
				}
				if(aux){
					d=dist(obs[i][0], obs[j][0]);
					adj[i*2-1].pb(mp(d,j*2-1));
					adj[j*2-1].pb(mp(d,i*2-1));
				}
				
				
				aux=1;
				rep(k, 1, n+1){
					if(j==k||i==k) continue;
					if(precalc(obs[i][0], obs[j][1], obs[k][0], obs[k][1])){  //tento ligar começo do obstaculo i
						aux=0;					//ao fim do obstaculo j
						break;
					}
				}
				if(aux){
					d=dist(obs[i][0], obs[j][1]);
					adj[i*2-1].pb(mp(d,j*2));
					adj[j*2].pb(mp(d,i*2-1));
				}
			
				aux=1;
				rep(k, 1, n+1){
					if(j==k||i==k) continue;
					if(precalc(obs[i][1], obs[j][0], obs[k][0], obs[k][1])){  //tento ligar fim do obstaculo i
						aux=0;				//ao começo do obstaculo j
						break;
					}
				}
				if(aux){
					d=dist(obs[i][1], obs[j][0]);
					adj[i*2].pb(mp(d,j*2-1));
					adj[j*2-1].pb(mp(d,i*2));
				}
				
				aux=1;
				rep(k, 1, n+1){
					if(j==k||i==k) continue;
					if(precalc(obs[i][1], obs[j][1], obs[k][0], obs[k][1])){  //tento ligar fim do obstaculo i
						aux=0;					//ao fim do obstaculo j
						break;
					}
				}
				if(aux){
					d=dist(obs[i][1], obs[j][1]);
					adj[i*2].pb(mp(d,j*2));
					adj[j*2].pb(mp(d,i*2));
				}
			}	
		}
		
		/*rep(i, 0, n*2+2){
			cout << i << " : ";
			rep(j, 0, adj[i].size())
				cout << adj[i][j].S << " " << adj[i][j].F << "  |||  ";
			cout << endl << endl;
		}*/
		
		double menor_dist=dijkstra(0,n*2+1,n*2+1);
		cout << menor_dist << endl;		
	} 
		
return 0;
}
