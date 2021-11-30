// Author: Gustavo Policarpo
// Name: Smallest on the Stack
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2929

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

stack <ii> st;
int N;

int main(){
	
	st.push(ii(0x3f3f3f3f, 0x3f3f3f3f));
	scanf("%d", &N);
	
	char op[10]; int v;
	while(N--){
		scanf("%s", op);
		if(op[1]=='U'){
			scanf("%d", &v);
			int at = min(v, st.top().S);
			st.push(ii(v, at));
		}
		else if(op[1]=='O'){
			if(st.top().F==0x3f3f3f3f){
				puts("EMPTY");
			}else{
				st.pop();
			}
		}
		else{
			if(st.top().F==0x3f3f3f3f){
				puts("EMPTY");
			}
			else{
				printf("%d\n", st.top().S);
			}
		}
	}	
	
	
			
	return 0;
}
