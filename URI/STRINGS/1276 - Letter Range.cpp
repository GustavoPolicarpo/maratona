// Author: Gustavo Policarpo
// Name: Letter Range
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1276

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
	string in;
	while(getline(cin, in)){
		sort(in.begin(), in.end());
		//cout << in << endl;
		int tam=in.size();
		int i=0;
		while(in[i]==' ') i++;
		bool mark=false; int last;
		while(i<tam){
			if(mark) cout << ", ";
			else mark=true;
			cout << in[i++] << ":";
			while(i<tam){
				if(in[i]>in[i-1]+1){
					cout << in[i-1];
					break;
				}
				i++;
			}
		}
		if(in.size()!=0)
			cout << in[i-1] << endl;
		else cout << endl;
	}
	
		
return (0);
}
