// Author: Gustavo Policarpo
// Name: Putting Plates on the Tuk...
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1890

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int C, D, T, out;
	cin >> T;
	while(T--){
		cin >> C >> D;
		out=0;
		if(C==0 && D==0){
			cout << 0 << endl;
			continue;
		}
		out=pow(26, C);
		out*=pow(10, D);
		cout << out << endl;
	}
	
	
return 0;
}


