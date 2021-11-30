// Author: Gustavo Policarpo
// Name: Morse
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2338

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
typedef pair < ii, int > iii;

string C1(string s){
	if(s==".-") return "a";
	if(s=="-...") return "b";
	if(s=="-.-.") return "c";
	if(s=="-..") return "d";
	if(s==".") return "e";
	if(s=="..-.") return "f";
	if(s=="--.") return "g";
	if(s=="....") return "h";
	if(s=="..") return "i";
	if(s==".---") return "j";
	if(s=="-.-") return "k";
	if(s==".-..") return "l";
	if(s=="--") return "m";
	if(s=="-.") return "n";
	if(s=="---") return "o";
	if(s==".--.") return "p";
	if(s=="--.-") return "q";
	if(s==".-.") return "r";
	if(s=="...") return "s";
	if(s=="-") return "t";
	if(s=="..-") return "u";
	if(s=="...-") return "v";
	if(s==".--") return "w";
	if(s=="-..-") return "x";
	if(s=="-.--") return "y";
	if(s=="--..") return "z";
	return "";
	
}
char C2(string s){
	if(s=="===") return '-';
	if(s=="=") return '.';
	cout << "here\n";
}

int t; string s;

int main()
{
	cin >> t;
	
	while(t--){
		
		cin >> s;
		rep(i, 0, 60) s.pb(3);
		
		string go, aux;
		rep(i, 0, s.size()-60){
			
			if(s.substr(i, 7)=="......."){
				if(aux.size()) go.pb(C2(aux));
				cout << C1(go);
				cout << " ";
				go.clear(), aux.clear();
				i+=6;
			}
			else if(s.substr(i, 3)=="..."){
				if(aux.size()) go.pb(C2(aux));
				cout << C1(go);
				go.clear(), aux.clear();
				i+=2;
			}
			else if(s.substr(i, 1)=="."){
				if(aux.size()) go.pb(C2(aux));
				aux.clear();
			}
			else{
				aux.pb(s[i]);
			}
			
		}
		
		if(aux.size()) go.pb(C2(aux));
		cout << C1(go);
		cout << '\n';
		
	}
	
	return 0;
	
}
