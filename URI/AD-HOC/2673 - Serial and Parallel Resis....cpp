// Author: Gustavo Policarpo
// Name: Serial and Parallel Resis...
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2673

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


vector <double> v, sol;

bool ver(double s){
	return s < 0;
}

void check(){
	int tam = sol.size()-1;
	while(tam>=2 && !ver(sol[tam]) && ver(sol[tam-1]) && !ver(sol[tam-2])){
		double op = sol[tam-1];
		double a = sol[tam-2];
		double b = sol[tam];
		double c;
		if(op==-'-') c = a+b;
		if(op==-'|') c = (a*b)/(a+b);
		sol.pop_back(), sol.pop_back(), sol.pop_back();
		sol.push_back(c);
		tam = sol.size()-1;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	// (10|20-(20-50)|80)-(1|2|80-90|(1-(50|50|60|20|20-20)|50)|30)
			// (5|5)-(10|(5-5))
			
	string s;
	while(getline(cin, s)){
		if(!s.size()) continue;
		
		v.clear();
		rep(i, 0, s.size()){
			double t = 0;
			if(s[i]>='0' && s[i]<='9'){
				while(i<s.size() && s[i]>='0' && s[i]<='9') t*=10, t+=s[i++]-'0'; i--;
				v.pb(t);
			}else{
				t = -s[i];
				v.pb(t);
			}
		}
		
		sol.clear();
		rep(i, 0, v.size()){
			if(v[i]==-')'){
				sol.erase(sol.begin()+sol.size()-2);
				check();
				continue;
			}
			sol.push_back(v[i]);
			check();
			
		}
		
		cout << fixed << setprecision(3) << sol[0] << '\n';
		
	}
		
	return 0;
	
}
