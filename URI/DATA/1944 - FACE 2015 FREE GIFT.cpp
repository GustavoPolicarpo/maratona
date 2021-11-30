// Author: Gustavo Policarpo
// Name: FACE 2015 FREE GIFT
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1944

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

#define INF 0x3F3F3F3F
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, cnt=0; cin >> N;
	stack <char> s; char aux;
	while(N--){
		if(s.empty()){
			s.push('F'), s.push('A'), 
			s.push('C'), s.push('E');
		}
		vector <char> in;
		//cout << s.top() << " " << s.size()<< endl;
		rep(i, 0, 4){
			scanf(" %c", &aux);
			if(aux==s.top()){
				//cout << aux << endl;
				s.pop();
				//cout << s.top() << endl;
				in.pb(aux);
			}
			else{
				for(int j=in.size()-1; j>=0; j--) s.push(in[j]);
				rep(j, 0, in.size()) s.push(in[j]);
				in.clear();
				s.push(aux);
			}
		}
		if(in.size()==4) cnt++;
		else{
			for(int j=in.size()-1; j>=0; j--) s.push(in[j]);
			rep(j, 0, in.size()) s.push(in[j]);
		}
		
	}
	
	printf("%d\n", cnt);
			

return 0;

}