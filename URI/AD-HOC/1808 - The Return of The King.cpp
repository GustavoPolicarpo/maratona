// Author: Gustavo Policarpo
// Name: The Return of The King
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1808

//#define gc getchar_unlocked
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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	string in; cin >> in;
	vector <int> num; int aux=in[0]-'0', cnt=0; double total=0;
	rep(i, 1, in.size()){
		//cout << aux << endl;
		if(in[i]==0+'0'){
			total+=aux*10;
			cnt++; i++;
			aux=in[i]-'0';
			continue;
		}
		else total+=aux, cnt++;
		aux=in[i]-'0';	
	}
	if(in[in.size()-1]!=0+'0') total+=in[in.size()-1]-'0', cnt++;
	//cout << total << " " << cnt << endl;
	//cout << double(total/cnt) << endl;
	printf("%.2lf\n", total/cnt);

return 0;
}



