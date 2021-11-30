// Author: Gustavo Policarpo
// Name: Diet Plan
// Level: 2
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1248

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

using namespace std;


int main()
{
	int N; cin >> N;
	cin.ignore();
	int d[200], c[200], r[200];
	while(N--)
	{
		
		string D, A, B;
		rep(i,'A','Z'+1) {
			d[i]=0;
			c[i]=0;
		} 
		getline(cin , D);
		rep(i,0,D.size()) d[D[i]]++;
		getline(cin , A);
		rep(i,0,A.size()) c[A[i]]++;
		getline(cin , B);
		rep(i,0,B.size()) c[B[i]]++;
		
		bool trapaceou=false;
		rep(i,'A','Z'+1) {
			r[i]=d[i]-c[i];
			if(r[i]<0){
				trapaceou=true;
				break;
			}
		}
		if(trapaceou==true)
			cout << "CHEATER";
		else
			rep(i,'A','Z'+1)
				while(r[i]>0){
					char out=i;
					cout << out;
					r[i]--;
				}
		cout << endl;		
	}
	
return 0;
}

