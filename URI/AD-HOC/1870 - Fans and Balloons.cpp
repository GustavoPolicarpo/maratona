// Author: Gustavo Policarpo
// Name: Fans and Balloons
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1870

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int L, C, P;
int mat[11][11];

void target(int x, int y)
{
	
	int pe, pd;
	rep(j, y, C+1) if(mat[x][j]!=0) pd=mat[x][j];
	reo(j, y, 0)   if(mat[x][j]!=0) pe=mat[x][j];
	
	y-=(pd-pe);
	if(y<1) y=1;
	else if(y>C) y=C;
	if(mat[x][y]!=0){
		cout << "BOOM" << ' ' << x+1 << ' ' << y << endl;
		return;
	}
	x++;
	
	if(x==L){
		cout << "OUT" << ' ' << y << endl;
		return;
	}
	
	target(x, y);		
}


int main()
{
	while(cin>>L>>C>>P and L+C+P){
	
	rep(i, 0, L)
		rep(j, 1, C+1)
			cin >> mat[i][j];
	
	target(0, P);
	
	}

return 0;
}
