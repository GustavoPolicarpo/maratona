// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Kit de Encolhimento de Po...
// Nível: 7
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2245

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define EPS 1e-12
#define INF ((1LL)<<60)
#define MAX 100010

struct point{
    double x, y;
    point(double _x=0, double _y=0){
        x = _x;
        y = _y;
    }
    void read(){ scanf("%lf %lf", &x, &y); }
    point operator - (point q){ return point(x - q.x, y - q.y); }
    point operator + (point q){ return point(x + q.x, y + q.y); }
    point operator / (double t){ return point(x/t, y/t); }
};

double cross(point a, point b){
    return a.x*b.y - a.y*b.x;
}

double dot(point a, point b){
    return a.x*b.x + a.y*b.y;
}

int ccw(point a, point b, point c){
    double ret = cross(b-a, c-b);
    if (ret > EPS) return 1;
    if (ret < -EPS) return -1;
    return 0;
}


int N;
point A, B;
point P[MAX];
point M[2][MAX];

int pivot; // will be M[a][0] or M[b][0]
int segundo;
int giro;

double TRIAREA(point a, point b, point c){
    point u = b - a;
    point v = c - a;
    return fabs(cross(u,v)/2.0);
}

double dp[MAX][2][2][2];

double f(int i, int u, int p, int ok){ // i = atual[0:N-1], u = ultimo[a:b], p = penultimo[a:b]
        if (ok > 0) ok = 1;
        
        if (i == N)
        {
            int turnPenultimoUltimoPrimeiro = ccw(M[p][N-2], M[u][N-1], M[pivot][0]);
            int turnoUltimoPrimeiroSegundo = ccw(M[u][N-1], M[pivot][0], M[segundo][1]);
            
            if (turnPenultimoUltimoPrimeiro != 0 && turnPenultimoUltimoPrimeiro != giro)
                return INF;                     
            
            if (turnoUltimoPrimeiroSegundo != 0 && turnoUltimoPrimeiroSegundo != giro)
                return INF; 
            
            if(!ok) ok = ok + turnPenultimoUltimoPrimeiro + turnoUltimoPrimeiroSegundo;

            if (ok) return 0;
            else return +INF;
        }

        double &r = dp[i][u][p][ok];
        if (r > -1) return r;
        r = INF;
                
        for (int at = 0; at < 2; at++) // escolher i do set A ou B
        {
            int turn = ccw(M[p][i-2], M[u][i-1], M[at][i]);
            if (turn == 0 || turn == giro)
            {
                r = min(r, TRIAREA(M[pivot][0], M[u][i-1], M[at][i]) + f(i+1, at, u, (ok==0?ok+turn:ok)));
            }
        }
        return r;
}
void init_dp(){
    rep(i, 0, N+1)
        rep(a, 0, 2)
            rep(b, 0, 2)
                rep(c, 0, 2)
                        dp[i][a][b][c] = -1;
}

int main(){
    while(cin >> N)
    {
        for (int i = 0; i < N; i += 1) P[i].read();
        A.read(), B.read();
    
        for (int i = 0; i < N; i += 1){
            M[0][i] = (A + P[i])/2.0;       
            M[1][i] = (B + P[i])/2.0;
        }
    
        double ans = -2, area;
        for (giro = -1; giro <= 1; giro += 2)
        {
        
            for (pivot = 0; pivot <= 1; ++pivot) // escolha do primeiro ponto M[pivot][0]
            {
                for (int u = 0; u <= 1; ++u) // escolha do segundo ponto M[u][1]
                {
                    segundo = u;
                    init_dp();
                    area = f(2, u, pivot, 0); // recursao M[ ? ][2...N-1]
                    if (ans < -1 || area < ans) ans = area;
                }
            }
        }
        printf("%.3lf\n", ans);
    
    }
    return 0;
}
