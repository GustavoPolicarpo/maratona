// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Diversão dos Alunos
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2116

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

int main()
{
	int N, M; cin >> N >> M;
	bool eh1=false, eh2=false;
	
	int a1=N, a2=M;
	while(!eh1){
		bool e=true;
		rep(i, 2, a1/2){
			if(a1%i==0){
				e=false;
				break;
			}
		}
		if(e) eh1=true;
		else a1--;
	}
	while(!eh2){
		bool e=true;
		rep(i, 2, a2/2){
			if(a2%i==0){
				e=false;
				break;
			}
		}
		if(e) eh2=true;
		else a2--;
	}
	cout << a1*a2 << endl;

return 0;
}
