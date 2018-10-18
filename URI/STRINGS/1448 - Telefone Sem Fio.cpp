// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Telefone Sem Fio
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1448

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
	int T; cin >> T; cin.ignore();
	rep(z, 1, T+1){
		string a, b, c;
		
		getline(cin, a), getline(cin, b), getline(cin, c);
		int t1=0, f1=-1, t2=0, f2=-1;
		rep(i, 0, a.size()){
			if(b[i]==a[i]) t1++;
			if(c[i]==a[i]) t2++;
			if(f1==f2){
				if((b[i]!=a[i])) f1=i;
				if((c[i]!=a[i])) f2=i;
			}
		}
		//cout << f1 << " " << f2 << endl;
		printf("Instancia %d\n", z);
		if(t1==t2){
			if(f1<f2) printf("time 1\n");
			else if(f2<f1) printf("time 2\n");
			else printf("empate\n");
		} 
		else if(t1>t2) printf("time 1\n");
		else printf("time 2\n");
		printf("\n");
	}
	
return 0;
}
