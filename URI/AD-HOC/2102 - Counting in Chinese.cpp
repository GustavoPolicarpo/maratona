// Author: Gustavo Policarpo
// Name: Counting in Chinese
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2102

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

//freopen("in.txt", "r", stdin);
//

int main()
{
	int T; cin >> T; bool esp=false;
	while(T--){
		int N, L; cin >> N >> L;
		map <ii, int> m;
		map <ii, int> ::iterator it;
		int p, l, c, v;
		rep(i, 0, L){
			scanf("%d %d %d %d", &p, &l, &c, &v);
			m[mp(l, c)]+=v;
		}
		if(esp) printf("\n");
		else esp=true;
		for(it=m.begin(); it!=m.end(); it++){
			ii aux=it->first; int t=it->second;
			printf("%d %d %d\n", aux.F, aux.S, t);
		}
	}

return 0;
}
