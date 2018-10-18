// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Espécies de Madeira
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1260

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
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N; cin >> N; cin.ignore();
	string aux; getline(cin, aux); bool mark=false;
	while(N--){
		if(mark) cout << endl;
		else mark=true;
		map <string, double> esp; double total=0; vector <string> out;
		while(getline(cin, aux) and aux!=""){
			if(!esp.count(aux))	out.pb(aux);
			esp[aux]++;
			total++;	
		}
		sort(out.begin(), out.end());
		cout << fixed << setprecision(4);
		rep(i, 0, out.size()){
			cout << out[i] << " ";
			cout << esp[out[i]]/total*100.0 << endl;
		}	
	}
	
return 0;
}
