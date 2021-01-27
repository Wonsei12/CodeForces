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
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

void solve() {
	ll N; cin >> N;

	vector<vector<vector<ll>>> dp(64, vector<vector<ll>>(2, vector<ll>(2, -1)));

	function<ll(int,int,int)> dfs = [&](int digit, int flowBit, int under) {
		ll& ret = dp[digit][flowBit][under];
		if(ret != -1)
			return ret;
		ret = 0;
		int curBit = (N >> digit) & 1;
		if(digit == 62) {
			if(flowBit == 0 && under == true) 
				return ret = 1LL;
			else
				return ret = 0LL;
		}
		for(int bit1 = 0 ; bit1 <= 1 ; bit1 ++) {
			for(int bit2 = 0 ; bit2 <= 1 ; bit2 ++) {
				if(bit2 > bit1) 
					continue;
				int nxtBit = (bit1 + bit2 + flowBit) >= 2;
				int calcedCurBit = (bit1 + bit2 + flowBit) & 1;
				int newUnder = under;
				if(calcedCurBit < curBit)
					newUnder = 1;
				else if(calcedCurBit > curBit) 
					newUnder = 0;
				ret += dfs(digit + 1, nxtBit, newUnder);
				ret %= MOD;
			}
		}
		return ret;
	};

	ll ans = dfs(0, 0, 1);
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; t = 1;
	while(t--)
		solve();
}