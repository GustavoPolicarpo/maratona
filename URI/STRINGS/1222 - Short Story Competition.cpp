// Author: Gustavo Policarpo
// Name: Short Story Competition
// Level: 6
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1222

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000

typedef long long int ll;
typedef pair < double, double > ii;
typedef pair < int, ii > iii;


int main()
{
	int N, L, C;
	while(cin >> N >> L >> C){ cin.ignore();
		bool ini=false; string in;
		int pag=1, l=0, c=0, e=1;
		rep(i, 0, N){

			cin >> in;
			int tam=in.size();
			
			if(c+tam<=C){
				c+=tam+e;
			}
			else{
				c=tam+e;
				l++;
				//cout << in << endl;
				if(l==L){
					l=0;
					pag++;
				}
			}
		}
		cout << pag << endl;		
	}
			
return (0);
}
