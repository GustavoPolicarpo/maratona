// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pontos Extras
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1758

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

//freopen("in.txt", "r", stdin);
//


int main()
{
//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	while(T--){
		int P, N;
		scanf("%d %d", &P, &N);
		rep(i, 0, N){
			double sum=0.0, in, media;
			vector <double> notas;
			rep(j, 0, P){
				scanf("%lf", &in);
				sum+=in; 
				notas.pb(in);
			}
			sort(notas.begin(), notas.end());
			reverse(notas.begin(), notas.end());
			//cout << sum << "  ";
			media=sum/P;
			//cout << media << endl;
			if(media<4.0){
				printf("%.2lf\n", media);
			}
			else if(media<7.0){
				rep(k, 0, P){
					if(notas[k]<7 && notas[k]>media){
						media=notas[k];
						break;
					}
				}
				printf("%.2lf\n", media);
			}
			else{
				rep(k, 0, P){
					if(notas[k]<=11 && notas[k]>media){
						media=notas[k];
						break;
					}
				}
				printf("%.2lf\n", media);
			}
		}
	}
		
return 0;
}

