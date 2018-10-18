// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Torre de Hanoi, Novamente!
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1166

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
//freopen("out.txt", "w", stdout);


int main()
{
	set<int> qp;
	rep(i, 1, 1234) qp.insert(i*i);
	int n[51], p[51]; memset(n, 0, sizeof n); memset(p, 0, sizeof p);
	int v=1, num=1; bool yep, take;
	while(v<51){
		yep=false;
		rep(i, 1, v+1){
		//	cout << v << " " << num << " " << p[i] << endl;
		//	system("pause");
			if(qp.count(p[i]+num)){
				p[i]=num;
				num++;
				yep=true;
				break;
			}
		}
		if(!yep){
			n[v-1]=num-1;
			v++;
			p[v]=num++;
		}
	}
	//rep(i, 0, v) cout << n[i] << " ";
	int N, T; cin >>T;
	while(T--){ 
		scanf("%d", &N);
		cout << n[N-1] << endl;
	}
	

return 0;
}
