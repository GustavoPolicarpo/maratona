// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Difícil de Acreditar, Mas...
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1728

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
#define error 1e-4

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < char, int > ii;
typedef pair < double, int > iii;

int main()
{	
	int a, b, c;
	string A, B, C, in;
	char nd;
	bool aux;
	
	while(cin >> in){
		if(in=="0+0=0") break;
		a=0, b=0, c=0; A="", B="", C="";
		int n=0;
		rep(i, 0, in.size()){
			if(in[i]=='+' || in[i]=='='){
				n++;
				continue;
			}
			if(n==0) A+=in[i];
			else if(n==1)B+=in[i];
			else C+=in[i];
		}
		
		aux=false;
		for(int i=A.size()-1; i>=0; i--){
			if(aux) a*=10, a+=A[i]-'0';
			else if(A[i]!='0') aux=true, a+=A[i]-'0';
		}
		aux=false;
		for(int i=B.size()-1; i>=0; i--){
			if(aux) b*=10, b+=B[i]-'0';
			else if(B[i]!='0') aux=true, b+=B[i]-'0';
		}
		aux=false;
		for(int i=C.size()-1; i>=0; i--){
			if(aux) c*=10, c+=C[i]-'0';
			else if(C[i]!='0') aux=true, c+=C[i]-'0';
		}
		
		if(a+b==c) cout << "True" << endl;
		else cout << "False" << endl;
	}
	cout << "True" << endl;
	
return 0;
}
