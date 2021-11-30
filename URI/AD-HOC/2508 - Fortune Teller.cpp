// Author: Gustavo Policarpo
// Name: Fortune Teller
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2508

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


int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	string in;
	map <char, int> C;
	string um="abcdefghijklmnopqrstuvwxyz", dois="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	rep(i, 0, um.size()){
		char aux=um[i];
		C[aux]=i%9 + 1;
			aux=dois[i];
		C[aux]=i%9 + 1;
	}
		
	while(getline(cin, in)){
		
		int num=0;
		rep(i, 0, in.size()){
			if(!isalpha(in[i])) continue;
			int aux=in[i];
			num+=C[aux];
		}
		
		int ans=num;
		while(1){
			int aux=0;
			while(num){
				aux+=num%10;
				num/=10;
			}
			if(aux==ans) break;
			ans=num=aux;
		}
		
		cout << ans << '\n';
		
	}

	return 0;
	
}
