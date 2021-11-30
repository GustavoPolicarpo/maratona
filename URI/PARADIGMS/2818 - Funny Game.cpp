// Author: Gustavo Policarpo
// Name: Funny Game
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2818

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


char s[100001];
int pd[100001][2][6];
int mark[100001][2][6];
int cnt = 2, tam;

int solve(int i, int y, int r){
	if(i==tam){
		if(y==1 && r==0) return 0;
		return 0x3f3f3f3f;
	}
	if(mark[i][y][r]==cnt) return pd[i][y][r];
	mark[i][y][r] = cnt;
	int ret = 0x3f3f3f3f;
	if(s[i]=='0'){
		if(y) ret = min(ret, solve(i+1, 1, (r*10)%6));
		ret = min(ret, solve(i+1, y, r)+1);
	}else{
		ret = min(ret, solve(i+1, 1, (r*10+s[i]-'0')%6));
		ret = min(ret, solve(i+1, y, r)+1);
	}
	return pd[i][y][r] = ret;
}

int main(){
	
	int t; scanf("%d", &t);
	while(t--){
		scanf("%s", s); tam = strlen(s); cnt++;
		if(s[0]=='0'){
			puts("0");
			continue;
		}
		int ans = solve(0, 0, 0);
		if(ans>=0x3f3f3f3f){
			int yep = 0;
			rep(i, 0, tam) if(s[i]=='0'){
				yep = 1;
				break;
			}
			if(yep) cout << tam-1 << '\n';
			else puts("Cilada");
		}
		else printf("%d\n", ans);
	}
			
	return 0;
}
