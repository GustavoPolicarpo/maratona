// Author: Gustavo Policarpo
// Name: Interplanetary
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2969

#include<bits/stdc++.h>

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define all(s) s.begin(), s.end()
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%lld", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;
const ll LINF = 1LL << 60;

const int MAXV = 200020;
const int MAXL = 22;

int N, R, Q;
ll mat[404][404];
ll base[404][404];

struct pl {
	int u, t;
};
pl planets[404];

struct qr {
	int a, b, k, t, id;
};
vector <qr> queries[2];

bool cmp(qr a, qr b) {
	return a.k < b.k;
}

vector <int> temps;
map<int, vector<int>> planetsPerTemp;

ll ans[100010];

void solve(int t) {
	rep(i, 1, N + 1) {
		rep(j, 1, N + 1) {
			mat[i][j] = base[i][j];
		}
	}

	int last = 1;
	rep(z, 0, queries[t].size()) {
		qr aux = queries[t][z];

		vector <int> planetsToUser;
		rep(k, last, aux.k + 1) {
			if (k > temps.size()) break;
			rep(j, 0, planetsPerTemp[temps[k - 1]].size()) {
				planetsToUser.push_back(planetsPerTemp[temps[k - 1]][j]);
			}
		}

		rep(k, 0, planetsToUser.size()) {
			int kk = planetsToUser[k];
			rep(i, 1, N + 1) {
				rep(j, 1, N + 1) {
					mat[i][j] = min(mat[i][j], mat[i][kk] + mat[kk][j]);
				}
			}
		}

		last = aux.k + 1;
		ans[aux.id] = mat[aux.a][aux.b];
	}
}

int main() {

	scanf("%d %d", &N, &R);

	rep(i, 1, N + 1) {
		scanf("%d", &planets[i].t);
		planetsPerTemp[planets[i].t].push_back(i);
		planets[i].u = i;
	}

	for (auto x : planetsPerTemp) {
		temps.push_back(x.first);
	}

	rep(i, 1, N + 1) rep(j, 1, N + 1) {
		base[i][j] = (i == j ? 0 : LINF);
	}

	int u, v, d;
	rep(i, 0, R) {
		scanf("%d %d %d", &u, &v, &d);
		base[u][v] = base[v][u] = d;
	}

	scanf("%d", &Q);

	qr qraux;
	rep(i, 0, Q) {
		scanf("%d %d %d %d", &qraux.a, &qraux.b, &qraux.k, &qraux.t);
		qraux.id = i;
		queries[qraux.t].pb(qraux);
	}

	sort(queries[0].begin(), queries[0].end(), cmp);
	solve(0);

	reverse(all(temps));
	sort(queries[1].begin(), queries[1].end(), cmp);
	solve(1);

	rep(i, 0, Q) {
		if (ans[i] == LINF) ans[i] = -1;
		cout << ans[i] << '\n';
	}

	return 0;
}
