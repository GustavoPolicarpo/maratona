// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: R+L=J
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2557

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;


int solve1(string s){
	int a=0, b=0, i=0;
	while(s[i]!='+'){
		a*=10;
		a+=s[i++]-'0';
	}	i++;
	while(s[i]!='='){
		b*=10;
		b+=s[i++]-'0';
	}
	return a+b;
}
int solve2(string s){
	int a=0, b=0, i=0;
	while(s[i]!='+'){
		a*=10;
		a+=s[i++]-'0';
	}	i++, i++, i++;
	while(i<s.size()){
		b*=10;
		b+=s[i++]-'0';
	}
	return b-a;
}
int solve3(string s){
	int a=0, b=0, i=2;
	while(s[i]!='='){
		a*=10;
		a+=s[i++]-'0';
	}	i++;
	while(i<s.size()){
		b*=10;
		b+=s[i++]-'0';
	}
	return b-a;
}
int main(){
	
	string s;
	
	while(cin >> s){
		if(s.find('J')!=-1) cout << solve1(s) << '\n';
		if(s.find('L')!=-1) cout << solve2(s) << '\n';
		if(s.find('R')!=-1) cout << solve3(s) << '\n';
	}
	
	return 0;
	
}
