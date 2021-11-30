// Author: Gustavo Policarpo
// Name: Polyglot Parrot
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2850

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 
int main(){
    
	string a;
	while(getline(cin, a)){
		if(a=="esquerda") puts("ingles");
		else if(a=="direita") puts("frances");
		else if(a=="nenhuma") puts("portugues");
		else puts("caiu");
	}
    
    return 0;
}  
