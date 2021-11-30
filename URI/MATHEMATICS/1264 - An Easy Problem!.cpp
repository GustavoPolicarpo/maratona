// Author: Gustavo Policarpo
// Name: An Easy Problem!
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1264

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second


typedef long long int ll;
typedef pair < int, int > ii;


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	map<char, int> B; int cnt=0;
	rep(i, '0', '9'+1) B[i]=cnt++;
	rep(i, 'A', 'Z'+1) B[i]=cnt++;
	rep(i, 'a', 'z'+1) B[i]=cnt++;

	string s;
	while(cin >> s){
		int ini=2, yep=1;
		rep(i, 0, s.size()) ini=max(ini, B[s[i]]+1);
		
		
		rep(z, ini, 62+1){
			int num=0;
			rep(i, s[0]=='-', s.size()){
				num*=z;
				num+=B[s[i]];
				num%=(z-1);
			}
			if(num==0){
				yep=0;
				printf("%d\n", z);
				break;
			}
		}
		
		if(yep) puts("such number is impossible!");
		
	}

	return 0;
	
}
