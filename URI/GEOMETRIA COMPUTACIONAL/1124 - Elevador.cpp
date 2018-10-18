// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Elevador
// Nível: 3
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1124

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;



int main(){
    int L, C; double R1, R2, R, Rm, aux1, aux2;
    while(cin>>L>>C>>R1>>R2 and L+C+R1+R2){
    	if(max(2*R1, 2*R2)>min(L, C)){
    		cout << 'N' << endl;
    		continue;
		}
		Rm=R1+R2;
		aux1=L-R1-R2;
		aux2=C-R1-R2;
		R=sqrt(aux1*aux1+aux2*aux2);
		//cout << Rm << " " << R << endl;
		if(Rm<=R)
			cout << 'S' << endl;
		else
			cout << 'N' << endl;	
	}
		
return 0;
}
