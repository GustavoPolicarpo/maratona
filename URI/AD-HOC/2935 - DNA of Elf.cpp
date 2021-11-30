// Author: Gustavo Policarpo
// Name: DNA of Elf
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2935

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;



vector <ll> elfs;
set <ll> st, st2;

void myerase(){
	vector <ll> vl; swap(vl, elfs);
	set <ll> l1, l2;
	swap(l1, st);
	swap(l2, st2);
}

int main(){
	
	int T; scanf("%d", &T);
	
	while(T--){
		int N; scanf("%d", &N); char spell[66]; int tam;
		myerase();
		st.clear(); elfs.clear(); st2.clear(); st.insert(0);
		
		rep(i, 0, N){
			scanf("%s", spell); tam = strlen(spell);
			ll aux = 0;
			rep(j, 0, tam){
				if(spell[j]>='0' && spell[j]<='9'){
					aux |= (1LL<<(spell[j]-'0'));
				}
				else if(spell[j]>='a' && spell[j]<='z'){
					aux |= (1LL<<(spell[j]-'a'+10));
				}
				else if(spell[j]>='A' && spell[j]<='Z'){
					aux |= (1LL<<(spell[j]-'A'+10+26));
				}
				else{
					while(42);
				}
			}
			st2.insert(aux);
			elfs.pb(aux);	
		}
		
		sort(elfs.begin(), elfs.end());
		elfs.erase( unique(elfs.begin(), elfs.end()), elfs.end());
		
		int pointer = 0;
		for(int bc=62; bc>=0; bc--){
			for(int j=pointer; j<elfs.size(); j++){
				if(!st.count(elfs[j]) && elfs[j]&(1LL<<bc)){
					swap(elfs[j], elfs[pointer]);
					break;
				}
			}
			if(pointer < elfs.size() && elfs[pointer]&(1LL<<bc)){
				st.insert(elfs[pointer]);
				for(int j=pointer+1; j<elfs.size(); j++){
					if(elfs[j]&(1LL<<bc)){
						elfs[j]^=elfs[pointer];
					}
				}
				pointer++;
			}
		}
		
		ll ans = 1, e = st.size()-1;
		rep(i, 0, e) ans = ans*2;
		ans = ans-1-st2.size();
		
		printf("%lld\n", ans);
		
		
	}	
	
	
	return 0;
}
