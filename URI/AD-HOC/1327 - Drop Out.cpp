// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Drop Out
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1327

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;

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



typedef pair < string, int > ii;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N;
	while(scanf("%d", &N) and N){
		vector <string> vec; string in;
		int saiu[N]; memset(saiu, 0, sizeof saiu);
		int carta[N]; memset(carta, 0, sizeof carta);
		rep(i, 0, N){
			cin >> in;
			vec.pb(in);
		}
		queue <int> q; int aux;
		rep(i, 0, 52){
			scanf("%d", &aux);
			q.push(aux);
		}
		int cnt, menor, fim=0;
		while(1){
			menor=INF, cnt=0;
			rep(i, 0, N){
				if(!saiu[i]){
					if(q.empty()){
						fim=1;
						break;
					}
					carta[i]=q.front();
					//cout << i << " " << carta[i] << endl;
					q.pop();
					
					menor=min(menor, carta[i]);
				}
			}
			if(fim){
				rep(i, 0, N){
					if(saiu[i]==2) saiu[i]=1;
					else if(!saiu[i]) saiu[i]=2;
				}
				break;
			}
			rep(i, 0, N){
				if(saiu[i]==1) continue;
				else if(saiu[i]==2) saiu[i]=1;
				else if(carta[i]==menor) saiu[i]=2;
			}
			
			rep(i, 0, N) if(saiu[i]) cnt++;
			if(cnt==N) break;
		}
		rep(i, 0, N){
			if(saiu[i]==2){
				cout << vec[i] << " ";
			}
		}
		cout << '\n';
	}

return 0;
}



