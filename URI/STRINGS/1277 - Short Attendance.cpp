// Author: Gustavo Policarpo
// Name: Short Attendance
// Level: 6
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1277

# include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

int main()
{
	int T,x;
	char NOME[110][51];
	char PRES[110][110];
	string PRE[110];
	
	cin >> T;
	while(T--){
		int N;
		
		cin >> N;
		
		rep(i, 0, N)
			cin >> NOME[i];
	
		rep(i, 0, N){
			cin >> PRES[i];
			PRE[i]=PRES[i];
		}
		
		double cont[N], cont2[N], cont3[N], M[N];
		
		rep(i, 0, N){
			cont[i]=0; cont2[i]=0; cont3[i]=0;
		}
		
		rep(i, 0, N){
			rep(j, 0, PRE[i].size()){
				if(PRE[i][j]=='A') cont[i]++;
				else if(PRE[i][j]=='P') cont2[i]++;
				else cont3[i]++;	
			}
			//cout << cont[i] << " " << cont2[i] << " " << cont3[i] << endl;
		}
		vector < string > nome;
		rep(i, 0, N){
			M[i] = cont[i]+cont2[i];
			if(cont2[i]<(0.75*M[i])) nome.pb(NOME[i]);	
		}
		bool mark=false;
		rep(i, 0, nome.size()){
			if(mark) cout << " ";
			else mark=true;
			cout << nome[i];
		}
		
		cout << endl;	
		
	}
	return 0;
}
