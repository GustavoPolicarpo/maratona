// Author: Gustavo Policarpo
// Name: Profit
// Level: 4
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1310

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define MAXN 51

int v[51];
int s, f, N;
int Sum1D()
{ 
	int ret = 0; int sum = 0; int saux;
	s = f = saux = 0;
	rep(i,0,N){
		sum += v[i];
			if(sum > ret){
				ret = sum;
				s = saux;
				f = i;
			}
			else if(sum < 0){
				sum = 0;
				saux = i+1;
			}
	}
	return ret;
}
int main()
{
	while(cin >> N){
		int c; cin >> c;
		rep(i, 0, N){
			int temp; cin >> temp;
			v[i]=temp-c;
		}
		int out=Sum1D();
		cout << out << endl;
	}

return 0;
}
