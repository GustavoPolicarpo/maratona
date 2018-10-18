// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Relógio Binário
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1561

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair < int, int > ii;
typedef pair < ii, int > iii;

const int INF = 0x3f3f3f3f;


/*
 ____________________________________________
|                                            |
|    ____________________________________    |_
|   |                                    |   |_)
|   |   8         4         2         1  |   |
|   |                                    |   |
|   |             o                      |   |
|   |                                    |   |
|   |                                    |   |
|   |         o                          |   |
|   |                                    |   |
|   |   32    16    8     4     2     1  |   |_
|   |____________________________________|   |_)
|                                            |
|____________________________________________|

*/
int main(){
	
	string a[6], b[5], c[2], d[7], e[7];
	a[0]=" ____________________________________________";
	a[1]="|                                            |";
	a[2]="|    ____________________________________    |_";
	a[3]="|   |                                    |   |_)";
	a[4]="|   |   8         4         2         1  |   |";
	a[5]="|   |                                    |   |";
	
	b[0]="|   |   ";
	b[1]="         ";
	b[2]="         ";
	b[3]="         ";
	b[4]="  |   |";
	
	c[0]="|   |                                    |   |";
	c[1]="|   |                                    |   |";
	
	d[0]="|   |   ";
	d[1]="     ";
	d[2]="     ";
	d[3]="     ";
	d[4]="     ";
	d[5]="     ";
	d[6]="  |   |";
	
	e[0]="|   |                                    |   |";
	e[1]="|   |   32    16    8     4     2     1  |   |_";
	e[2]="|   |____________________________________|   |_)";
	e[3]="|                                            |";
	e[4]="|____________________________________________|";
	
	int H, M;
	while(scanf("%d:%d", &H, &M) !=EOF){
		if(H==-1) break;
		int h[5], m[10]; 
		
		int aux=1<<3, i=0;
		while(aux){
			if(H-aux>=0) H-=aux, h[i]=1;
			else h[i]=0;
			aux>>=1, i++;
		}aux=1<<5, i=0;
		while(aux){
			if(M-aux>=0) M-=aux, m[i]=1;
			else m[i]=0;
			aux>>=1, i++;
		}
		
		rep(i, 0, 6) cout << a[i] << '\n';
		rep(i, 0, 4){
			cout << b[i];
			if(h[i]) cout << 'o';
			else cout << ' ';
		}	cout << b[4] << '\n';
		rep(i, 0, 2) cout << c[i] << '\n';
		rep(i, 0, 6){
			cout << d[i];
			if(m[i]) cout << 'o';
			else cout << ' ';
		}	cout << d[6] << '\n';
		rep(i, 0, 5) cout << e[i] << '\n';
		cout << '\n';
		
	}
	
	return 0;
	
}
