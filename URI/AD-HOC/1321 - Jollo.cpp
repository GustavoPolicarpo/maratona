// Author: Gustavo Policarpo
// Name: Jollo
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1321

#define gc getchar_unlocked
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

#define INF 1e13
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, double > ii;
typedef pair < double, int > iii;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int ela[3], ele[2];
    while(1){
    	scanf("%d %d %d %d %d", &ela[0], &ela[1], &ela[2],
			&ele[0], &ele[1]);
		set <int> cartas;
		rep(i, 0, 3) cartas.insert(ela[i]);
		rep(i, 0, 2) cartas.insert(ele[i]);
		if(ela[0]==0) break;
		sort(ela, ela+3);
		sort(ele, ele+2);
		
		int cnt=0;
		for(int i=1; i>=0; i--){
			bool yep=false;
			rep(j, 0, 3){
				if(ela[j]>ele[i]){
					ela[j]=-1;
					yep=true;
					break;
				}
			}
			if(!yep) cnt++;
		} int ans;
		if(cnt==0){
			printf("-1\n");
			continue;
		} 
		else if(cnt==2){
			rep(i, 1, 53)
				if(!cartas.count(i)){
					ans=i;
					break;
				}
		}
		else{
			for(int i=2; i>=0; i--){
				//cout << ela[i] << endl;
				if(ela[i]!=-1){
					ans=ela[i]+1;
					while(cartas.count(ans)) ans++;
					break;
				}
			}
		}
		if(ans>52){
			printf("-1\n");
			continue;
		}
		printf("%d\n", ans);
	}
    
    
return 0;
}


