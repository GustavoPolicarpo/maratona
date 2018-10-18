// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Escrita Rápida, o Duelo
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2844

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int check(int Am, int Rm, int Em, int Av, int Rv, int Ev, int S){
	int Ta = Am*2 + Rm + Em*S;	
	int Tb = Av*2 + Rv + Ev*S;
	if(Ta<Tb) return -1;
	if(Ta==Tb) return 0;
	if(Ta>Tb) return 1;
}

int main(){
	
	int Am, Rm, Em, Av, Rv, Ev; string S;
	cin >> Am >> Rm >> Em >> Av >> Rv >> Ev;
	getline(cin, S); getline(cin, S);
	
	int result = check(Am, Rm, Em, Av, Rv, Ev, S.size());
	
	if(result==-1) puts("Matheus");
	if(result==0) puts("Empate");
	if(result==1) puts("Vinicius");
	

	return 0;
}
