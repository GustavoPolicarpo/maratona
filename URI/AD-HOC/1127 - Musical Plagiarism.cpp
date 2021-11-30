// Author: Gustavo Policarpo
// Name: Musical Plagiarism
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1127

//#define gc getchar_unlocked
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
#define MAXN 100001
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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int pi[MAXN], res[MAXN], nres;
int kmp (string text, string pattern){ 
	nres = 0; pi[0] = -1; 
	for (int i = 1; i < pattern.size(); ++i){ 
		pi[i] = pi[i-1]; 
		
		while (pi[i] >= 0 && pattern[pi[i] + 1] != pattern[i])
			pi[i] = pi[pi[i]]; 
			
		if (pattern[pi[i] + 1] == pattern[i]) ++pi[i]; 
	}
	int k = -1; //k + 1 eh o tamanho do match atual 
	for (int i = 0; i < text.size(); ++i){ 
	
		while (k >= 0 && pattern[k + 1] != text[i]) 
			k = pi[k]; 
			
		if (pattern[k + 1] == text[i]) ++k; 
		if (k + 1 == pattern.size() && (i==text.size() ||text[i+1]!='#')){ 
			res[nres++] = i - k;
			k = pi[k]; 
		} 
	} 
	return nres;
}

int toint(string n){
	if(n=="C" || n=="B#") return 0;
	if(n=="C#" || n=="Db") return 1;
	if(n=="D") return 2;
	if(n=="D#" || n=="Eb") return 3;
	if(n=="E" || n=="Fb") return 4;
	if(n=="F" || n=="E#") return 5;
	if(n=="F#" || n=="Gb") return 6;
	if(n=="G") return 7;
	if(n=="G#" || n=="Ab") return 8;
	if(n=="A") return 9;
	if(n=="A#" || n=="Bb") return 10;
	if(n=="B" || n=="Cb") return 11;
}

string tonota(int n){
	if(n==0) return "C";
	if(n==1) return "C#";
	if(n==2) return "D";
	if(n==3) return "D#";
	if(n==4) return "E";
	if(n==5) return "F";
	if(n==6) return "F#";
	if(n==7) return "G";
	if(n==8) return "G#";
	if(n==9) return "A";
	if(n==10) return "A#";
	if(n==11) return "B";
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, M;
	while(scanf("%d %d", &N, &M) and N){
		string musica, trecho[12], aux;
		rep(i, 0, N){
			cin >> aux;
			musica+=tonota(toint(aux));
		}
		//cout << musica << endl;
		rep(i, 0, M){
			cin >> aux;
			rep(j, 0, 12){
				trecho[j]+=tonota((toint(aux)+j)%12);
			}
		}
		//rep(j, 0, 12)
		//	cout << trecho[j] << endl;
		
		bool yep=false;
		rep(i, 0, 12){
			if(kmp(musica, trecho[i])){
				yep=true; //cout << nres << " " << res[0] << endl;
				break;
			}
		}
		if(yep) puts("S");
		else puts("N");		
	}
    
    return 0;
}


