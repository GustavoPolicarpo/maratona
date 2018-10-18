// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Campeão
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2040

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	
	int N;
	while(cin >> N and N){
		map<string, int> mapa;
		string tim; int pnt;
		rep(i, 0, N){
			cin >> tim >> pnt;
			mapa[tim] = pnt;
		}
		string a, b; int pa, pb;
		rep(i, 0, N/2){
			cin >> a;
			scanf("%d-%d", &pa, &pb);
			cin >> b;
			mapa[a]+=pa*3;
			mapa[b]+=pb*3;
			if(pa==pb) mapa[a]++, mapa[b]++;
			else if(pa>pb) mapa[a]+=5;
			else mapa[b]+=5;
		}
		int maior = 0;
		map<string, int> :: iterator it;
		for(it = mapa.begin(); it!=mapa.end(); it++){
			if(it->second > maior){
				maior = it->second;
				tim = it->first;
			}
		}
		if(tim=="Sport"){
			printf("O Sport foi o campeao com %d pontos :D\n", maior);
		}else{
			printf("O Sport nao foi o campeao. O time campeao foi o %s com %d pontos :(\n", tim.c_str(), maior);
		}
		puts("");
	}


	return 0;
}

