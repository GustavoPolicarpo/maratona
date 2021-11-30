// Author: Gustavo Policarpo
// Name: The Change
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2685

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef pair < int, int > ii;




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int n;
	while(cin >> n){
		//while(n<0) n+=360;
		//n%=360;
		if(n>=0 && n<=89) puts("Bom Dia!!");
		else if(n>=90 && n<=179) puts("Boa Tarde!!");
		else if(n>=180 && n<=269) puts("Boa Noite!!");
		else if(n>=270 && n<=359) puts("De Madrugada!!");
		else if(n==360) puts("Bom Dia!!");
		
	}	
	

	return 0;
	
}
