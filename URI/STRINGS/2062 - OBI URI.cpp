// Author: Gustavo Policarpo
// Name: OBI URI
// Level: 4
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2062

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;


int main()
{
		
	int N; cin >> N;
	string in;
	bool mark=false;
	rep(i, 0, N){
		if(mark)
			cout << " ";
		else
			mark=true;
		cin >> in;
		if(in.size()==3&&in[0]=='O'&&in[1]=='B')
			in="OBI";
		else if(in.size()==3&&in[0]=='U'&&in[1]=='R')
			in="URI";
		cout << in;
	}
	cout << endl;
return (0);
}
