// Author: Gustavo Policarpo
// Name: Closing Tabs
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2061

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
	int N, Q;
	cin >> N >> Q;
	int ini=N;
	string in;
	rep(i, 0, Q){
		cin >> in; 
		if(in=="fechou")
			ini++;
		else{
			ini--;
			if(ini<0)
				ini=0;
		}	
	}
	cout << ini << endl;

return (0);
}
