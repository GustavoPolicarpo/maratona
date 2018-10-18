// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Renzo e a Decoração Capic...
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1880

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

char alfa[]={"0123456789abcdef"};
int main()
{
	int T, N; cin >> T;
	while(T--){
		cin >> N; bool mark=false;
		rep(i, 2, 17){
			string bx;
			int aux=N;
			while(aux){
				bx+=alfa[aux%i];
				aux/=i;
			}
			string bxx=bx;
			reverse(bx.begin(), bx.end());
			if(bxx==bx){
				if(mark) cout << " ";
				else mark=true;
				cout << i;
			}
		}
		if(!mark) cout << "-1";
		cout << endl;
	}

return 0;
}


