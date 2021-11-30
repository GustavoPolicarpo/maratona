// Author: Gustavo Policarpo
// Name: Containers
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2237

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
#define MAXV 100001
const int mod = 1e9 + 7;
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
//typedef pair < int, int > ii;
//typedef pair < int, ii > iii;

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


vector <int> v1, v2, aux;
set <vector <int> > s;
map<vector <int> , int > dist;
typedef pair < int, vector <int> > ii;

int bfs(){
	priority_queue <ii> pq;
	pq.push(mp(0, v1)); dist[v1]=0;
	while(!pq.empty()){
		v1=pq.top().S; int c=-pq.top().F; pq.pop();
		
		//rep(i, 0, 8)
		//	cout << v1[i] << " ";
	//	cout << endl;
		
		if(v1==v2){
			return c;
		}
		
		rep(i, 0, 2)
		rep(j, 0, 3){
			aux=v1;
			swap(aux[i*4+j], aux[i*4+j+1]);
			if(dist.count(aux)){
				if(dist[aux]<=dist[v1]+aux[i*4+j]+aux[i*4+j+1]) continue;
				dist[aux]=dist[v1]+aux[i*4+j]+aux[i*4+j+1];
				pq.push(mp(-dist[aux], aux));
			} else{
				dist[aux]=dist[v1]+aux[i*4+j]+aux[i*4+j+1];
				pq.push(mp(-dist[aux], aux));
			}
		}

		rep(j, 0, 4){
			aux=v1;
			swap(aux[j], aux[j+4]);
			if(dist.count(aux)){
				if(dist[aux]<=dist[v1]+aux[j]+aux[j+4]) continue;
				dist[aux]=dist[v1]+aux[j]+aux[j+4];
				pq.push(mp(-dist[aux], aux));
			} else{
				dist[aux]=dist[v1]+aux[j]+aux[j+4];
				pq.push(mp(-dist[aux], aux));
			}
		}
	}
}
int main()
{
	int aux;
	rep(i, 0, 8) scanf("%d", &aux), v1.pb(aux);
	rep(i, 0, 8) scanf("%d", &aux), v2.pb(aux);
	
	int out=bfs();
	
	printf("%d\n", out);
	

	
	
return 0;
}
