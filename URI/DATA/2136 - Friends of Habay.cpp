// Author: Gustavo Policarpo
// Name: Friends of Habay
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2136

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
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct amg{
	string nome, op;
};

bool cmp(amg a, amg b)
{
	if(a.op=="YES" && b.op=="YES"){
		if(a.nome>b.nome) return false;
		return true;
	}
	if(a.op=="YES" && b.op=="NO"){
		return true;
	}
	if(a.op=="NO" && b.op=="YES"){
		return false;
	}
	if(a.op=="NO" && b.op=="NO"){
		if(a.nome>b.nome) return false;
		return true;
	}	
}

int main()
{
	vector <amg> out;
	set <string> ja;
	string win;
	int cont=0; amg aux;
	while(cin >> aux.nome){
		if(aux.nome=="FIM") break;
		cin >> aux.op;
		if(ja.count(aux.nome)) continue;
		if(aux.op=="YES" && aux.nome.size()>cont){
			win=aux.nome, cont=aux.nome.size();
		}
		out.pb(aux); ja.insert(aux.nome);	
	}
	sort(out.begin(), out.end(), cmp);
	
	rep(i, 0, out.size()){
		cout << out[i].nome << endl;
	}
	printf("\nAmigo do Habay:\n");
	cout << win << endl;
	
			
return 0;
}
