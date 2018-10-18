// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Abreviações
// Nível: 5
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1519

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
typedef pair < int, ii > iii;



int main()
{

	string in; 
	while(getline(cin, in)){
		if(in==".") break;
		map <string, int> cv;
		map <string, int> qt;
		map <char, string> pas;
		map <char, string>:: iterator it;
		map <char, int> tam;
		string aux=""; int cnt=0;
		vector <string> en;
		rep(i, 0, in.size()){
			if(in[i]==' '){
				en.pb(aux);
				qt[aux]++;
				aux="";
			}
			else aux+=in[i];
		}
		en.pb(aux);
		qt[aux]++;
		
		rep(i, 0, en.size()){
			aux=en[i];
			if(aux.size()<3) continue;
			char use=aux[0];
			//cout << tam[use] << endl;
			if(tam[use]<=(aux.size()-2)*qt[aux]){	
				cv[pas[use]]=0;
				pas[use]=aux;
				tam[use]=(aux.size()-2)*qt[aux];
				cv[aux]=1;
			}
		}
		rep(i, 0, en.size()){
			if(i>0) cout << " ";
			aux=en[i];
			if(cv[aux]==1){
				cnt++;
				cout << aux[0] << ".";
			}
			else cout << aux;
		}
		cout << endl << pas.size() << endl;
		for(it=pas.begin(); it!=pas.end(); it++){
			cout << it->first << ". = " << pas[it->first] << endl;
		}
						
	}
	
return 0;
}

