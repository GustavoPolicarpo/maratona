// Author: Gustavo Policarpo
// Name: Fantastic Beasts
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2908

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<ll, ll> ii;
typedef pair<unsigned long long int, ll> iii;


struct Triple{
	ll d, x, y; // long long ?
	Triple(){}
	Triple (ll q, ll w, ll e):d(q), x(w), y(e){}
};

Triple egcd (ll a, ll b){
	if (!b) return Triple(a, (ll)1, (ll)0);
	Triple q = egcd(b, a%b);
	return Triple(q.d, q.y, q.x - a/b * q.y);
}

iii val[11][101];
int rip[11][101];
int B, Z;
ull cmp = -1;

iii solve(ii a, ii b){
	if(a.F > b.F) swap(a, b);
	if(a.S!=0) a.F += ((b.F-a.F)/a.S)*a.S;
	//a.F + a.S*x = b.F + b.S*y
	//a.S*x - b.S*y = b.F - a.F
	if(a.S==0 && b.S==0){
		if(a.F==b.F) return ii(a.F, 0);
		return ii(cmp, -1);
	}
	else if(a.S==0){
		ll auxy = a.F-b.F;
		if(auxy%b.S==0){
			auxy = auxy/b.S;
			if(auxy<0) return ii(cmp, -1);
			else return ii(b.F+auxy*b.S, 0);
		}else{
			return ii(cmp, -1);
		}
	}
	else if(b.S==0){
		ll auxx = b.F-a.F;
		if(auxx%a.S==0){
			auxx = auxx/a.S;
			if(auxx<0) return ii(cmp, -1);
			else return ii(a.F+auxx*a.S, 0);
		}else{
			return ii(cmp, -1);
		}
	}
	else{
		Triple aux = egcd(a.S, -b.S);
		//cout << a.F << " " << a.S << " " << b.F << " " << b.S << " " << aux.d << " " << aux.x << " " << aux.y << " " << __gcd(a.S, -b.S) <<  '\n';
		if((b.F-a.F)%(aux.d)==0){
			Triple xua;
			aux.x *= ((b.F-a.F)/aux.d);
			aux.y *= ((b.F-a.F)/aux.d);
			xua.x = b.S/__gcd(a.S, b.S), xua.y = (a.S/__gcd(a.S, b.S));
			
			if(aux.x < 0 && xua.x <= 0) return ii(cmp, -1);
			ll qt1 = (-aux.x+xua.x-1)/xua.x;
			if(aux.x < 0){
				aux.x+=(ull)qt1*xua.x;
				if(aux.y<0) aux.y+=(ull)qt1*xua.y, qt1 = 0;
			}else{
				qt1 = 0;
			}
			
			if(aux.y < 0 && xua.y <= 0) return ii(cmp, -1);
			ll qt2 = (-aux.y+xua.y-1)/xua.y;
			if(aux.y < 0){
				aux.y+=(ull)qt2*xua.y;
				if(aux.x<0) aux.x+=(ull)qt2*xua.x, qt2 = 0;
			}else{
				qt2 = 0;
			}
			
			
			ll q1, q2, qt;
			if(!xua.x) q1 = -1;
			else q1 = aux.x/xua.x+qt2;
			if(!xua.y) q2 = -1;
			else q2 = aux.y/xua.y+qt1;
			
			if(q1==-1)  aux.y-=(ull)q2*xua.y;
			else if(q2==-1) aux.x-=(ull)q1*xua.x;
			else qt = min(q1, q2), aux.x-=(ull)qt*xua.x, aux.y-=(ull)qt*xua.y;
			
			
			return ii((ull)aux.x*a.S+a.F, a.S/__gcd(a.S, b.S)*b.S);
		}else{
			return ii(cmp, -1);
		}
	}
}
int main(){
	
	scanf("%d %d", &B, &Z);
	rep(i, 0, B){
		int P[Z+1];
		rep(j, 0, Z+1) scanf("%d", &P[j]);
		int vis[Z+1], pai[Z+1];
		memset(vis, -1, sizeof vis);
		memset(pai, -1, sizeof pai);
		rep(j, 0, Z+1) val[i][j] = ii(cmp, -1);
		int pos = P[0], t = 0;
		while(42){
			if(vis[pos]!=-1){
				int fim = pos, cicle = t-vis[pos];
				while(pai[pos]!=fim){
					val[i][pos].S = cicle;
					pos = pai[pos];
				}
				val[i][pos].S = cicle;
				break;
			}else{
				vis[pos] = t;
				val[i][pos] = ii(t, 0);
				pai[P[pos]] = pos;
				pos = P[pos];
				t++;
			}
		}
		rep(j, 1, Z+1) if(val[i][j].F==cmp) rip[i][j] = 1;
		//rep(j, 1, Z+1) cout << j << " " << val[i][j].F << " " << val[i][j].S << '\n';
		//puts("************");
	}
	rep(i, 0, B-1){
		rep(j, 1, Z+1){
			if(rip[i][j] || rip[i+1][j]){
				rip[i+1][j] = 1;
				continue;
			}
			val[i+1][j] = solve(val[i][j], val[i+1][j]);
			//cout << i << " " << j << "  " << val[i+1][j].F << " " << val[i+1][j].S << '\n';
			if(val[i+1][j].F==cmp) rip[i+1][j] = -1;
		}
	}
	
	unsigned long long int tempo = cmp;
	
	int id = -1;
	rep(j, 1, Z+1){
		//if(rip[B-1][j]) continue;
		//cout << val[B-1][j].F << " " << val[B-1][j].S << '\n';
		if(val[B-1][j].F != cmp && !rip[B-1][j]){
			if(val[B-1][j].F < tempo){
				id = j;
				tempo = val[B-1][j].F;
			}
		}
	}	
	
	if(id==-1) puts("*");
	else{
		cout << id << " ";
		string resp;
		while(tempo){
			resp.pb(tempo%10+'0');
			tempo/=10;
		}
		reverse(resp.begin(), resp.end());
		if(!resp.size()) resp.pb('0');
		cout << resp << '\n';
		
	}
	
	return 0;
}
