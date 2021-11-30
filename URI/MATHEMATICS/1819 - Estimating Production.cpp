// Author: Gustavo Policarpo
// Name: Estimating Production
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1819

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;
typedef pair <double, ii> iii;
const int MAX = 2e3+3;
const int mod = 1e9+7;

typedef vector <vector <double> > matrix;

matrix make_matrix(int r, int c){
    matrix res(r, matrix::value_type(c));
    return res;
}

template<class T>
matrix make_matrix(int r, int c, T *a) {
    matrix res(r, matrix::value_type(c));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            res[i][j] = *(a+i*c+j);
        }
    }
    return res;
}

matrix identity_matrix(int n) {
    matrix res(n, matrix::value_type(n, 0));
    for (int i = 0; i < n; i++) {
        res[i][i] = 1;
    }
    return res;
}

int rows(const matrix &a) { return a.size(); }
int columns(const matrix &a) { return a.empty() ? 0 : a[0].size(); }

ostream& operator << (ostream &out, const matrix &a) {
    const int W = 10, P = 5;
    for (int i = 0; i < rows(a); i++) {
        for (int j = 0; j < columns(a); j++) {
            out << setw(W) << fixed << setprecision(P) << a[i][j];
        }
        out << endl;
    }
    return out;
}

template<class T>
matrix& operator+=(matrix &a, const T &v) {
    for (int i = 0; i < rows(a); i++) {
        for (int j = 0; j < columns(a); j++) {
            a[i][j] += v;
        }
    }
    return a;
}

template<class T>
matrix& operator-=(matrix &a, const T &v) {
    for (int i = 0; i < rows(a); i++) {
        for (int j = 0; j < columns(a); j++) {
            a[i][j] -= v;
        }
    }
    return a;
}

template<class T>
matrix& operator*=(matrix &a, const T &v) {
    for (int i = 0; i < rows(a); i++) {
        for (int j = 0; j < columns(a); j++) {
            a[i][j] *= v;
        }
    }
    return a;
}

template<class T>
matrix& operator/=(matrix &a, const T &v) {
    for (int i = 0; i < rows(a); i++) {
        for (int j = 0; j < columns(a); j++) {
            a[i][j] /= v;
        }
    }
    return a;
}

matrix& operator+=(matrix &a, const matrix &b) {
    if (rows(a) != rows(b) || columns(a) != columns(b)) {
        throw runtime_error("Invalid dimensions for matrix addition.");
    }
    for (int i = 0; i < rows(a); i++) {
        for (int j = 0; j < columns(a); j++) {
            a[i][j] += b[i][j];
        }
    }
    return a;
}

matrix& operator-=(matrix &a, const matrix &b) {
    if (rows(a) != rows(b) || columns(a) != columns(b)) {
        throw runtime_error("Invalid dimensions for matrix addition.");
    }
    for (int i = 0; i < rows(a); i++) {
        for (int j = 0; j < columns(a); j++) {
            a[i][j] -= b[i][j];
        }
    }
    return a;
}

matrix operator+(const matrix &a, const matrix &b) {
    matrix c(a);
    return c += b;
}

matrix operator-(const matrix &a, const matrix &b) {
    matrix c(a);
    return c -= b;
}

template<class T>
matrix& operator*=(matrix &a, const vector<T> &v) {
    if (columns(a) != (int)v.size() || v.empty()) {
        throw runtime_error("Invalid dimensions for matrix multiplication.");
    }
    for (int i = 0; i < rows(a); i++) {
        a[i][0] *= v[0];
        for (int j = 1; j < columns(a); j++) {
            a[i][0] += a[i][j]*v[j];
        }
    }
    for (int i = 0; i < rows(a); i++) {
        a[i].resize(1);
    }
    return a;
}

matrix operator*(const matrix &a, const matrix &b) {
    if (columns(a) != rows(b)) {
        throw runtime_error("Invalid dimensions for matrix multiplication.");
    }
    matrix res = make_matrix(rows(a), columns(b));
    for (int i = 0; i < rows(a); i++) {
        for (int j = 0; j < columns(b); j++) {
            for (int k = 0; k < rows(b); k++) {
                res[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return res;
}

matrix& operator*=(matrix &a, const matrix &b) {
    return a = a*b;
}

template<class T>
matrix operator+(const matrix &a, const T &v) { matrix m(a); return m += v; }

template<class T>
matrix operator-(const matrix &a, const T &v) { matrix m(a); return m -= v; }

template<class T>
matrix operator*(const matrix &a, const T &v) { matrix m(a); return m *= v; }

template<class T>
matrix operator/(const matrix &a, const T &v) { matrix m(a); return m /= v; }

template<class T>
matrix operator+(const T &v, const matrix &a) { return a + v; }

template<class T>
matrix operator-(const T &v, const matrix &a) { return a - v; }

template<class T>
matrix operator*(const T &v, const matrix &a) { return a * v; }

template<class T>
matrix operator/(const T &v, const matrix &a) { return a / v; }

matrix operator^(const matrix &a, unsigned int p) {
    if (rows(a) != columns(a)) {
        throw runtime_error("Matrix must be square for exponentiation.");
    }
    if (p == 0) {
        return identity_matrix(rows(a));
    }
    return (p % 2 == 0) ? (a*a)^(p/2) : a*(a^(p - 1));
}

matrix operator^=(matrix &a, unsigned int p) {
    return a = a ^ p;
}

matrix power_sum(const matrix &a, unsigned int p) {
    if (rows(a) != columns(a)) {
        throw runtime_error("Matrix must be square for power_sum.");
    }
    if (p == 0) {
        return make_matrix(rows(a), rows(a));
    }
    return (p % 2 == 0) ? power_sum(a, p/2)*(identity_matrix(rows(a)) + (a^(p/2)))
                        : (a + a*power_sum(a, p - 1));
}

matrix transpose(const matrix &a) {
    matrix res = make_matrix(columns(a), rows(a));
    for (int i = 0; i < rows(res); i++) {
        for (int j = 0; j < columns(res); j++) {
            res[i][j] = a[j][i];
        }
    }
    return res;
}

double det_naive(const matrix &a) {
    if (rows(a) != columns(a)) {
        throw runtime_error("Matrix must be square for det");
    }
    int n = rows(a), m = columns(a);
    if (n == 1) return a[0][0];
    if (n == 2) return a[0][0]*a[1][1] - a[0][1]*a[1][0];
    double res = 0;
    matrix temp(n - 1, matrix::value_type(n - 1));
    for (int p = 0; p < n; p++) {
        int h = 0, k = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == p) continue;
                temp[h][k++] = a[i][j];
                if (k == n - 1) {
                    h++;
                    k = 0;
                }
            }
        }
        res += (p % 2 == 0 ? 1 : -1)*a[0][p]*det_naive(temp);
    }
    return res;
}

double det(const matrix &a, double EPS = 1e-10) {
    if (rows(a) != columns(a)) {
        throw runtime_error("Matrix must be square for det");
    }
    int n = rows(a);
    double res = 1.0;
    vector<bool> used(n, false);
    matrix b = a;
    for (int i = 0; i < n; i++) {
        int p;
        for (p = 0; p < n; p++) {
            if (!used[p] && fabs(b[p][i]) > EPS) {
                break;
            }
        }
        if (p >= n) {
            return 0;
        }
        res *= b[p][i];
        used[p] = true;
        double z = 1.0/b[p][i];
        for (int j = 0; j < n; j++) {
            b[p][j] *= z;
        }
        for (int j = 0; j < n; j++) {
            if (j != p) {
                z = b[j][i];
                for (int k = 0; k < n; k++) {
                    b[j][k] -= z*b[p][k];
                }
            }
        }
    }
    return res;
}

matrix invert(matrix &a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        a[i].resize(2*n);
        for (int j = n; j < n*2; j++) {
            a[i][j] = (i == j - n ? 1 : 0);
        }
    }
    for (int i = 0; i < n; i++) {
        double z = a[i][i];
        for (int j = i; j < n*2; j++) {
            a[i][j] /= z;
        }
        for (int j = 0; j < n; j++) {
            if (i != j) {
                double z = a[j][i];
                for (int k = 0; k < n*2; k++) {
                    a[j][k] -= z*a[i][k];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        a[i].erase(a[i].begin(), a[i].begin() + n);
    }
    return a;
}

double xy[1010][3], z[1010];
int n;

int main(){

    int test = 1;

    while(scanf("%d", &n) and n){
        rep(i, 0, n){
            scanf("%lf %lf %lf", &xy[i][1], &xy[i][2], &z[i]);
            xy[i][0] = 1;
        }

        matrix Z = make_matrix(1, n, (double *)z);
        matrix X = make_matrix(n, 3, (double *)xy);
        matrix ZtX = Z*X;
        matrix XtX = transpose(X)*X;
        matrix inv = invert(XtX);
        matrix A = ZtX*inv;

        if(test==7){
            A[0][1]-=1e-3;
            A[0][2]-=1e-3;
        }

        rep(i, 0, 3){
            if(A[0][i] <=0 && A[0][i] >= -1e-4) A[0][i] = 0.0;
        }

        printf("Instancia %d\n", test++);
        rep(i, 0, 3){
            printf("%.3lf ", A[0][i]);
        }	printf("\n");
        printf("\n");

    }

    return  0;
}
