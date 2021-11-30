// Author: Gustavo Policarpo
// Name: Game of Matchings
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2350

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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



int KMP(vector <int> &text, vector <int> &pattern)
{
    int ret = 0;
    int n = text.size(), m = pattern.size();
    vector<int> T(m+2);
 	
    int k = T[0] = -1;
    rep(i, 0, m)
    {
        while( ~k && pattern[i] != pattern[k] && ( pattern[k] || pattern[i] <= k ) ) k = T[k];
        T[i + 1] = ++k;
    }
    
    
    k = 0;
    rep(i, 0, n)
    {
        while( ~k && text[i] != pattern[k] && ( pattern[k] || text[i] <= k ) ) k = T[k];
        ++k;
        if( k == m ) ++ret, k = T[k];
    }
    
    return ret;
    
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	vector <int> text, pattern;
	char in[500050]; scanf("%s", in);
	int last[30], aux, n=strlen(in); memset(last, -1, sizeof last);
	
	rep(i, 0, n){
		aux=in[i]-'a';
		
		if(last[aux]==-1) text.pb(0);
		else text.pb(i-last[aux]);
		
		last[aux]=i;
	}
	
	cin >> n;
	memset(last, -1, sizeof last);
	
	rep(i, 0, n){
		scanf("%d", &aux);
		
		if(last[aux]==-1) pattern.pb(0);
		else pattern.pb(i-last[aux]);
		
		last[aux]=i;
	}
	
    printf("%d\n", KMP(text, pattern));
    
    return 0;
    
}
