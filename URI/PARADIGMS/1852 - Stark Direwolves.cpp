// Author: Gustavo Policarpo
// Name: Stark Direwolves
// Level: 6
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1852

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

const int MAXN = 202;
int prefer[2*MAXN][MAXN];
int N;

bool wPrefersM1OverM(int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;
 
        if (prefer[w][i] == m)
           return false;
    }
}

map <string, int> c, l;
map <int, string> rc, rl;

void stableMarriage()
{
    int wPartner[N];
 
    bool mFree[N];
 
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;
 
    while (freeCount > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;
 
        for (int i = 0; i < N && mFree[m] == false; i++)
        {
            int w = prefer[m][i];
            
            if (wPartner[w-N] == -1)
            {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }
 
            else  
            {
                int m1 = wPartner[w-N];
 
                if (wPrefersM1OverM(w, m, m1) == false)
                {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            } 
        } 
    } 
 
    /*cout << "Woman   Man" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << i+N << "\t" << wPartner[i] << endl;*/
    
    map<int, int> ans;
    for (int i = 0; i < N; i++) ans[wPartner[i]]=i+N;
    
    rep(i, 0, N){
    	cout << rc[i] << " " << rl[ans[i]] << '\n';
	}
    
}
 
int main()
{
	cin >> N;
	
	int cc=0, ll=N;
	string in, nome;
	
	rep(i, 0, N){
		cin >> nome;
		c[nome]=cc++;
		rc[c[nome]]=nome;
		rep(j, 0, N){
			cin >> in;
			if(!l.count(in)) l[in]=ll++, rl[l[in]]=in;
			prefer[c[nome]][j]=l[in];
		}
	}
	
	rep(i, 0, N){
		cin >> nome;
		rep(j, 0, N){
			cin >> in;
			prefer[l[nome]][j]=c[in];
		}
	}
	
	stableMarriage();

	return 0;
	
}
