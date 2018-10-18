// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quadrado Mágico
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2318

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	
	int mat[5][5];
	
	rep(i, 0, 3) rep(j, 0, 3) cin >> mat[i][j];
	
	if(mat[0][0]==0 and mat[1][1]==0 and mat[2][2]==0){
		int sum=0;
		rep(i, 0, 3) rep(j, 0, 3) sum+=mat[i][j];
		sum/=2;
		mat[0][0]=sum-mat[0][1]-mat[0][2];
		mat[1][1]=sum-mat[1][0]-mat[1][2];
		mat[2][2]=sum-mat[2][0]-mat[2][1];
	}
	else if(mat[0][2]==0 and mat[1][1]==0 and mat[2][0]==0){
		int sum=0;
		rep(i, 0, 3) rep(j, 0, 3) sum+=mat[i][j];
		sum/=2;
		mat[0][2]=sum-mat[0][0]-mat[0][1];
		mat[1][1]=sum-mat[1][0]-mat[1][2];
		mat[2][0]=sum-mat[2][1]-mat[2][2];
	}else{
		int sum=0;
		if(mat[0][0] && mat[0][1] && mat[0][2]) rep(i, 0, 3) sum+=mat[0][i];
		else if(mat[1][0] && mat[1][1] && mat[1][2]) rep(i, 0, 3) sum+=mat[1][i];
		else if(mat[2][0] && mat[2][1] && mat[2][2]) rep(i, 0, 3) sum+=mat[2][i];
		else if(mat[0][0] && mat[1][0] && mat[2][0]) rep(i, 0, 3) sum+=mat[i][0];
		else if(mat[0][1] && mat[1][1] && mat[2][1]) rep(i, 0, 3) sum+=mat[i][1];
		else if(mat[0][2] && mat[1][2] && mat[2][2]) rep(i, 0, 3) sum+=mat[i][2];
		else if(mat[0][0] && mat[1][1] && mat[2][2]) rep(i, 0, 3) sum+=mat[i][i];
		else if(mat[0][2] && mat[1][1] && mat[2][0]) rep(i, 0, 3) sum+=mat[i][2-i];
		
		rep(a, 0, 5)
		rep(i, 0, 3){
			rep(j, 0, 3){
				if(mat[i][j]==0){
					int cnt=0;
					rep(k, 0, 3) if(mat[i][k]==0) cnt++;
					if(cnt==1){
						int aux=0;
						rep(k, 0, 3) aux+=mat[i][k];
						mat[i][j]=sum-aux;
					}else{
						cnt=0;
						rep(k, 0, 3) if(mat[k][j]==0) cnt++;
						if(cnt==1){
							int aux=0;
							rep(k, 0, 3) aux+=mat[k][j];
							mat[i][j]=sum-aux;
						}
					}
				}
			}
		}
		
	}
	
	rep(i, 0, 3){
		rep(j, 0, 3){
			if(j) cout << " ";
			cout << mat[i][j];
		}
		cout << '\n';
	}
	
	return 0;
	
}

