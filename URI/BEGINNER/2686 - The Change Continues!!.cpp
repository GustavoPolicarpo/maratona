// Author: Gustavo Policarpo
// Name: The Change Continues!!
// Level: 5
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2686

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < ll, ll > ii;


int main(){
	
	double M; 
	while(cin >> M){
		int seg, min, hor; ll x;
		/*
		360 - 86400
		M - x
		*/
		double n = M;
		if(n>=0 && n<90 || n==360) puts("Bom Dia!!");
		else if(n>=90 && n<180) puts("Boa Tarde!!");
		else if(n>=180 && n<270) puts("Boa Noite!!");
		else if(n>=270 && n<360) puts("De Madrugada!!");
		x = M*86400.0/360.0;
		
		seg = x%60;
		min = (x/60)%60;
		hor = x/3600;
		hor = (hor+6)%24;
		
		printf("%02d:%02d:%02d\n", hor, min, seg);
	}
	
	return 0;
}
