// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Contando Caracters
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2108

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
	string s, t, maior; int m=0, aux=0;
	while(getline(cin, s)){
		if(s=="0") break;
		bool tra=false;
		rep(i, 0, s.size()){
			if(s[i]==' '){
				if(tra) printf("-");
				else tra=true;
				printf("%d", aux);
				if(aux>=m) maior=t, m=aux;
				aux=0, t="";
			}
			else t+=s[i], aux++;	
		}
		if(tra) printf("-");
		printf("%d\n", aux);
		if(aux>=m) maior=t, m=aux;
		aux=0, t="";
	}
	printf("\nThe biggest word: ");
	cout << maior << endl;

return 0;
}
