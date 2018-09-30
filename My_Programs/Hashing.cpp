const ll mod = 1e9 + 7; //modulo do hash
const ll x = 2; //num. primo > que o maior caracter de S.
ll H[NN], X[NN];

ll V(char c){ return c-'0'; }

ll my_hash(int i, int j){
	ll ret = H[j];
	if(!i) return ret;
	return ((ret-(H[i-1]*X[j-i+1])%mod)+mod)%mod;
}

void precompute(string s){
	X[0] = 1;
	rep(i, 1, NN)
		X[i] = (X[i-1]*x)%mod;
	H[0] = V(s[0]);
	rep(i, 1, s.size())
		H[i] = ((H[i-1]*x)%mod + V(s[i]))%mod;
}
