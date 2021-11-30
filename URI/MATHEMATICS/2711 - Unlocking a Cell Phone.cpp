// Author: Gustavo Policarpo
// Name: Unlocking a Cell Phone
// Level: 10
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2711

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

struct Triple{
    long long d, x, y; // long long ?
    Triple (long long q, long long w, long long e):d(q), x(w), y(e){}
};
Triple egcd (long long a, long long b){
    if (!b) return Triple(a, 1, 0);
    Triple q = egcd(b, a%b);
    return Triple(q.d, q.y, q.x - a/b * q.y);
}
// retorna o inverso modular de A modulo N .: (A * inv(A)) % N = 1
long long invMod (long long a, long long n){
    Triple t = egcd (a, n);
    if (t.d > 1) return 0;
    return (t.x%n+n)%n;
}

/*Determinar o menor E tal que B^E = N (mod P), -1 se for impossivel. Requer: Bezout Theorem*/
ll bsgs(ll b, ll n, ll p){
    if (n == 1) return 0;
    unordered_map <ll, int> table;
    ll m = sqrt(p) + 1, pot = 1, pot2 = 1;
    for (int j = 0; j < m; ++j){
        if (pot == n) return j;
        table[(n * invMod(pot, p)) % p] = j;
        pot = (pot * b) % p;
    }
    for (int i = 0; i < m; ++i){
        if (table.find(pot2) != table.end())
            return i * m + table[pot2];
        pot2 = (pot * pot2) % p;
    }
    return -1;
}


int main(){

	ll B, N, M;
	while(scanf("%lld %lld %lld", &B, &N, &M)!=EOF){
		printf("%lld\n", bsgs(B, N, M));
	}
	
    return 0;
}
