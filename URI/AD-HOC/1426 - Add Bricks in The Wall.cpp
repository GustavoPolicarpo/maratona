// Author: Gustavo Policarpo
// Name: Add Bricks in The Wall
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1426

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/



int main()
{
	int T; cin >>T;
	int mat[10][10];
	while(T--){
		scanf("%d", &mat[0][0]);
		scanf("%d %d", &mat[2][0], &mat[2][2]);
		scanf("%d %d %d", &mat[4][0], &mat[4][2], &mat[4][4]);
		scanf("%d %d %d %d", &mat[6][0], &mat[6][2], &mat[6][4], &mat[6][6]);
		scanf("%d %d %d %d %d", &mat[8][0], &mat[8][2], &mat[8][4], &mat[8][6], &mat[8][8]);
		for(int i=1; i<8; i+=2){
			mat[8][i]=(mat[6][i-1]-mat[8][i-1]-mat[8][i+1])/2;	
		}
		for(int i=7; i>=0; i--){
			for(int j=0; j<=i; j++){
				mat[i][j]=mat[i+1][j]+mat[i+1][j+1];
			}
		}
		for(int i=0; i<9; i++){
			for(int j=0; j<i; j++){
				cout << mat[i][j] << " ";
			}
			cout << mat[i][i] << endl;
		}
		
	}

		
return 0;
}
