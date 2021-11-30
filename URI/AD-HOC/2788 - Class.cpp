// Author: Gustavo Policarpo
// Name: Class
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2788

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

string N; int M;
char pd[20][200002][14], way[20][200002][14];
int T[14], memo[14][14];

int save(int p, char j){
	if(memo[p][j-'0']!=-1) return memo[p][j-'0'];
	int k = p;
	while( ~k && j != N[k]) k = T[k];
	k++;
    return memo[p][j-'0'] = k;
}

void buildT(){
	int k = T[0] = -1;
    rep(i, 0, N.size()){
        while( ~k && N[i] != N[k] ) k = T[k];
        T[i + 1] = ++k;
    }
    //rep(i, 0, N.size()+1) cout << T[i] << " "; cout << '\n';
}

char solve(int i, int m, int p){
	if(i+p+1<N.size()) return 0;
	while(m>=M) m-=M;
	if(i==0) return (m==0 && p==N.size());
	char &ret = pd[i][m][p];
	if(ret!=-1) return ret; ret = 0;
	for(char j=0; j<10; j++){
		ret |= solve(i-1, (m*10+j), p == N.size() ? p : N[p]==j+'0' ? p+1 : save(p, j+'0'));
		if(ret){
			way[i][m][p] = j;
			break;
		}
	}
	return ret;
}

string ans;
void back(int i, int m, int p){
	while(m>=M) m-=M;
	if(i==0) return; int j = way[i][m][p];
	ans.pb(j+'0'); 
	back(i-1, (m*10+j), p == N.size() ? p : N[p]==j+'0' ? p+1 : save(p, j+'0'));
}

int main(){
	
	cin >> N >> M;
	
	memset(memo, -1, sizeof memo);
	memset(pd, -1, sizeof pd);
	
	buildT();
	
	for(int t = 1; ; t++){
		if(solve(t, 0, 0)){
			back(t, 0, 0);
			break;
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
