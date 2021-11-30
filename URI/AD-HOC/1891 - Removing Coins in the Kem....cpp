// Author: Gustavo Policarpo
// Name: Removing Coins in the Kem...
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1891

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;


int main()
{
	
	int T; cin >> T;
	while(T--){
		int n; cin >> n;
		char N[n];
		int td=0;
		rep(i, 0, n){
			cin >> N[i];
			if(N[i]=='D')
				td++;
		}	
		if(n==0){
			cout << 'Y' << endl;
			continue;
		}
		if(td%2==0){
			cout << 'N' << endl;
			continue;
		}
		cout << 'Y' << endl;
		vector <int> out;
		rep(i, 0, n){
			if(N[i]=='D'){
				if(N[i+1]=='B') N[i+1]='D';
				else N[i+1]='B';
				
				out.pb(i+1);
				int j=i-1;
				while(j>=0&&N[j]!='D')
					out.pb(j+1), j--;	
			}
		}
		rep(i, 0, n-1)
			cout << out[i] << " ";
		cout << out[n-1] << endl;		
	}
	
return 0;
}
