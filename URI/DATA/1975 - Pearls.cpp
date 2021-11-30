// Author: Gustavo Policarpo
// Name: Pearls
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1975

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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;


void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main ()
{
	int P, A, R; string use;
	while(scanf("%d %d %d", &P, &A, &R) and P+A+R){
		cin.ignore();
		set <string> perolas;
		rep(i, 0, P){
			getline(cin, use);
			perolas.insert(use);
		}
		map<string, int> aluno;
		map<string, int>::iterator it; int maximo=0;
		rep(i, 0, A){
			string name;
			cin >> name; cin.ignore();
			set <string> used;
			int aux=-1;
			if(aluno.count(name)){
				aux=aluno[name];
				aluno[name]=0;
			}
			rep(j, 0, R){
				getline(cin, use);
				if(used.count(use)) continue;
				used.insert(use);
				if(perolas.count(use)){
					aluno[name]++;
					maximo=max(maximo, aluno[name]);
				}
			}
			aluno[name]=max(aluno[name], aux);
		}
		bool yep=false;
		for(it=aluno.begin(); it!=aluno.end(); it++){
			if(it->second == maximo){
				if(yep)	cout << ", ";
				else  yep=true;
				cout << it->first;
			}
		}
		cout << '\n';
	}
	
  
  return 0;
}

