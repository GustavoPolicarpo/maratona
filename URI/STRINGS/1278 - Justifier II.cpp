// Author: Gustavo Policarpo
// Name: Justifier II
// Level: 1
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1278

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
typedef pair < int, ii > iii;



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N; string in; bool mark=false, yep, yep2;
	vector <string> s;
	while(cin >> N){
		if(!N) break;
		if(mark) printf("\n");
		else mark=true;
		cin.ignore(); int mt=0, cnt;
		rep(i, 0, N){
			yep=false, yep2=false;
			getline(cin, in); cnt=in.size();
			string aux;
			rep(i, 0, cnt){
				if(!isspace(in[i])){
					if(yep&&yep2) aux+=" ";
					yep=false; yep2=true;
					aux+=in[i];
				}
				else yep=true;

			}
			//cout << aux << endl; 
			cnt=aux.size();
			mt=max(mt, cnt);
			s.pb(aux);
		}
		rep(i, 0, N){
			in=s[i]; cnt=in.size();
			while(cnt<mt){
				printf(" ");
				cnt++;
			}
			cout << in << '\n';
		}
		s.clear();
	}

	
	
return 0;
}
