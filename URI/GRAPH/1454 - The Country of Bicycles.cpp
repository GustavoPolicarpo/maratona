// Author: Gustavo Policarpo
// Name: The Country of Bicycles
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1454

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int m[101][101];
int N, M;

void floyd()
{
	int k, i, j;
	rep(k, 1, N+1)
	rep(i, 1, N+1)
	rep(j, 1, N+1)
	m[i][j]=min(m[i][j], max(m[i][k], m[k][j]));
}

int main()
{
	int z=1;
	while(cin >> N >> M and N+M){
		memset(m, INF, sizeof(m));
		int x, y, h;
		rep(i, 0, M){
			scanf("%d %d %d", &x, &y, &h);
			m[x][y]=h;
			m[y][x]=h;
		}
		
		floyd();
		
		/*rep(i, 1, N+1){
			rep(j, 1, N+1)
				cout << m[i][j] << " ";
			cout << endl;	
		}*/
		
		printf("Instancia %d\n", z);
		int k; cin >> k;
		int i, j, out;
		while(k--){
			scanf("%d %d", &i, &j);
			if(i!=j)	out=m[i][j];
			else 		out=0;
			printf("%d\n", out);
		}
		z++;
		cout << endl;	
	}
return 0;
}
