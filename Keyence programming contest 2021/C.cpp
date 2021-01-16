#define LOCAL

#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2")

#define IOS ios::sync_with_stdio(false);cin.tie(0)
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define LLINF 0x3f3f3f3f3f3f3f3f
#define INF 0x3f3f3f3f
#define uniq(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define sz(x) (int)x.size()
#define pw(x) (1LL<<x)

using pii = pair<int, int>;
using ll = long long;
const ll MOD = 998244353LL;
const long double PI = acos(-1.0);

ll add(ll x, ll y) {
	x+=y; x%=MOD;
	return x;
}
ll sub(ll x, ll y) {
	x-=y; x%=MOD; if(x<0) x+=MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x*y)%MOD;
}
ll bin_pow(ll x, ll p) {
	if(p==0) return 1;
	if(p&1) return mult(x,bin_pow(x,p-1));
	return bin_pow(mult(x,x),p/2);
}
ll rev(ll x) {
	return bin_pow(x,MOD-2);
}

void solve() {
	int h, w, k; cin >> h >> w >> k;
	int tmp = k;
	vector<vector<int>> G(h, vector<int>(w));
	vector<vector<ll>> dp(h+1, vector<ll>(w+1));
	while(tmp--) {
		int x, y; cin >> x >> y; x--, y--;
		char c; cin >> c;
		if(c=='R')
			G[x][y] = 1;
		else if(c=='D')
			G[x][y] = 2;
		else
			G[x][y] = 3;
	}
	ll tot = 1;
	for(int i=0 ; i<h*w-k ; i++) {
		tot *= 3;
		tot %= MOD;
	}
	dp[0][0] = tot;
	ll r3 = rev(3);
	for(int i=0 ; i<h ; i++) {
		for(int j=0 ; j<w ; j++) {
			if(G[i][j] == 0) {
				ll gak = dp[i][j] * r3;
				dp[i][j+1] += gak * 2;
				dp[i][j+1] %= MOD;
				dp[i+1][j] += gak * 2;
				dp[i+1][j] %= MOD;
			} else if(G[i][j] == 1) {
				dp[i][j+1] += dp[i][j];
			} else if(G[i][j] == 2) {
				dp[i+1][j] += dp[i][j];
			} else if(G[i][j] == 3) {
				dp[i+1][j] += dp[i][j];
				dp[i+1][j] %= MOD;
				dp[i][j+1] += dp[i][j];
				dp[i][j+1] %= MOD;
			}
 		}
	}
	cout << dp[h-1][w-1] << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}