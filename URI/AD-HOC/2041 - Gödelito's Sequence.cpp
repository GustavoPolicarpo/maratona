// Author: Gustavo Policarpo
// Name: Gödelito's Sequence
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2041

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001

#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < int, ii > iii;


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main(){
	
	vector <string> out; out.pb(" ");
	string num="3", atual=""; out.pb(num);
	rep(i, 0, 42){
		int last=num[0], cnt=0;
		rep(j, 0, num.size()){
			if(last==num[j]) cnt++;
			else{
				atual+=cnt+'0';
				atual+=last;
				last=num[j];
				cnt=1;
			}
		}
		atual+=cnt+'0';
		atual+=last;
		num=atual; atual="";
		out.pb(num);
		//cout << num << endl;
	}
	
	int N;
	while(scanf("%d", &N) !=EOF){
		cout << out[N] << '\n';
	}
	
	
	return 0;
}
