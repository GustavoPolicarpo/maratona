// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Enigma
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2699

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
typedef pair < int, int > ii;

string s;
int pd[1010][1010], mat[1010][1010], yep, k;

int solve(int i, int m){
	
	if(yep==2) return 1;
	
	if(i==s.size()){
		if(m==0) return pd[i][m] = yep = 2;
		return pd[i][m] = 1;
	}
	
	if(pd[i][m]) return pd[i][m];
	
	int ret = 1;
	
	if(s[i]=='?'){
		rep(j, (i==0), 10){
			ret = solve(i+1, (m*10+j)%k);
			if(ret==2){
				mat[i][m] = j;
				//cout << mat[i][m] << '\n';
				break;
			}
		}
	}else{
		ret = solve(i+1, (m*10+s[i]-'0')%k);
		mat[i][m] = s[i]-'0';
		//cout << mat[i][m] << '\n';
	}
	
	return pd[i][m] = ret;
}

string ans;
void rec(int i, int m){
	if(i==s.size()) return;
	ans.pb(mat[i][m]+'0');
	rec(i+1, (m*10+mat[i][m])%k);
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	cin >> s >> k;
	solve(0, 0);
	
	if(yep<2){
		puts("*");
		return 0;
	}
	
	rec(0, 0);
	cout << ans << '\n';
	

	return 0;
	
}
