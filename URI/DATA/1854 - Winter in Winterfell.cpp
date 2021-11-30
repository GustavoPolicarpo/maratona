// Author: Gustavo Policarpo
// Name: Winter in Winterfell
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1854

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

ll bit[1010][1010], place[1010][1010];
int L, C;
ll fat[10000005];

void update(int x, int y, int val){
    int yy;
    while(x <= L){
        yy = y;
        while(yy <= C){
            bit[x][yy] += val;
            yy += (yy & -yy);
        }
        x += (x & -x);
    }
}

int query(int x, int y){
    int yy, sum = 0;
    while(x > 0){
        yy = y;
        while(yy > 0){
            sum += bit[x][yy];
            yy -= (yy & -yy);
        }
        x -= (x & -x);
    }
    return sum;
}

#define mod 1000000007
ll fastexp(ll a,int b)
{
	ll x;

	if(b==0) return 1;	
	if(b==1) return a;

	if(b%2==0){
		x = fastexp(a,b/2)%mod;
		return (x*x)%mod;
	}
	else{
		return (a*fastexp(a,b-1))%mod;
	}
}

ll inverso(ll a)
{
  return fastexp(a,mod-2);
}


ll combina(ll n, ll k)
{   
   ll num, den, ret;
   num = fat[n+k-1];
   
   den = (fat[k] * fat[n - 1]) % mod;
   den = inverso(den);
   
   ret = (num * den) % mod;

   return ret;
}

int main()
{
	memset(bit, 0, sizeof bit);
	memset(place, 0, sizeof place);
	fat[0]=1;
	for(ll i=1; i<=10000000; i++)
		fat[i]=(fat[i-1]*i)%mod;
		
	scanf("%d %d", &L, &C); cin.ignore();
	string in, aux; int z=1;
	while(getline(cin, in)){
		int ind=0, vet[5]; aux="";
		rep(i, 0, in.size()){
			if(in[i]==' '){
				int tempo=0;
				rep(k, 0, aux.size()){
					tempo*=10;
					tempo+=aux[k]-'0';
				}
				vet[ind++]=tempo; aux="";
			}
			else{
				aux+=in[i];
			}	
		}
		int tempo=0;
		rep(k, 0, aux.size()){
			tempo*=10;
			tempo+=aux[k]-'0';
		}
		vet[ind++]=tempo;
		if(ind==2){
			update(vet[0], vet[1], -place[vet[0]][vet[1]]);
			place[vet[0]][vet[1]]=0;
		}
		else if(ind==3){
			update(vet[0], vet[1], vet[2]);
			place[vet[0]][vet[1]]+=vet[2];
		}
		else if(ind==5){
			int a, b, c, d; 
			int s=vet[4];
			a=min(vet[0], vet[2]), b=min(vet[1], vet[3]),
			c=max(vet[0], vet[2]), d=max(vet[1], vet[3]);
			int resp=query(c, d);
			if(a>1) resp-=query(a-1, d);
			if(b>1) resp-=query(c, b-1);
			if(a>1 && b>1) resp+=query(a-1, b-1);
			ll out=combina(resp, s);
			printf("Day #%d: %lld\n", z++, out);
		}
	}
	
    return 0;
}


