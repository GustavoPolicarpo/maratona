// Author: Gustavo Policarpo
// Name: Different Digits
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1285

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
typedef pair < double, int > iii;

int all[5005];

int main()
{
	memset(all, 0, sizeof(all));
	int n=1;
	rep(i, 0, 5002){
		int aux=i, temp=aux%10;
		set <int> num;
		while(aux>=1){
			if(num.count(temp)){
				n--;
				break;
			}
			num.insert(temp);
			aux/=10, temp=aux%10;
		}
		all[i]=n++;
	}
	
	int N, M;
	while(cin >> N >> M){
		cout << all[M]-all[N-1] << endl;
	}

return (0);	
}
