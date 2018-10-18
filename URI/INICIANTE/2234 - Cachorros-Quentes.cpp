// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cachorros-Quentes
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2234

#define gc getchar
#define pc(x) putchar(x);
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

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

inline double getDouble(FILE *f = stdin) {
    char ch;
    bool seen = false;
    bool sign = false;
    char values[10];
    double result =0.;
    bool beforeDot = true;
    int beforeLength = 0;
    double multiplier;

    while((ch = getc(stdin)) != EOF) {
        if(ch == '-') {
            sign = true;
            continue;
        }
        if(ch == ' ' || ch == '\n') {
            if(seen) break;
            continue;
        }
        if(ch == '.') {
            beforeDot = false;
            multiplier = 1.;
            while(beforeLength) {
                result += (double)(values[--beforeLength] - '0') * multiplier;
                multiplier *= 10.;
            }
            multiplier = 10.;
        }
        else {
            if(!beforeDot)
            {
                result += double(ch - '0') / multiplier;
                multiplier *= 10.;
            } else {
                values[beforeLength++] = ch;
            }
            seen = true;
        }
    }
    if(beforeDot) {
        multiplier = 1;
        while(beforeLength) {
            result += (double)(values[--beforeLength] - '0') * multiplier;
            multiplier *= 10.;
        }
    }

    if(sign) result *= -1.;

    return result;
}

int main()
{

	double H, P;
	H=getDouble(), P=getDouble();
	printf("%.2lf\n", H/P);
	

return 0;
}


