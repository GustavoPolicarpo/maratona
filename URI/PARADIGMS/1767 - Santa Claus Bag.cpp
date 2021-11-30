// Author: Gustavo Policarpo
// Name: Santa Claus Bag
// Level: 4
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1767

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair


int peso[101], valor[101], pd[101][51], aux[101][51];
int pac;

int bag(int i, int c)
{
	if(i == pac) return 0;
	if(pd[i][c] != -1) return pd[i][c];
	int ret = bag(i+1,c);
	int comp=0;
	if(c-peso[i] >= 0) comp = (bag(i+1,c-peso[i])+valor[i]);
	if(comp>ret) aux[i][c]=1;
	return pd[i][c] = max(ret, comp);
}

int pc, ps;
void back( int i, int c ){
	if( i == pac ) return;
	if( aux[i][c] ){
		pc++;
		ps+=peso[i];
		back( i+1, c - peso[i] );
	}
	else
		back( i+1, c );	
}

int main ()
{
	int N; cin >> N;
	
	while(N--){
		cin >> pac;
		rep(i, 0, pac){
			int v, p;
			cin >> v >> p;
			peso[i]=p;
			valor[i]=v;
		}
		
		pc=0; ps=0;
		rep(i, 0, pac+1)
			rep(j, 0, 51){
				pd[i][j]=-1;
				aux[i][j]=0;		
			}
		
		int out=bag(0, 50);
				back(0, 50);
		
		cout << out << " brinquedos" << endl;
		cout << "Peso: " << ps << " kg" << endl;
		cout << "sobra(m) " << pac-pc << " pacote(s)" << endl;
		cout << endl;
		
	}
   
}
