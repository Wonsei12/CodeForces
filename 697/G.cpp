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
	int n; cin >> n;
	vector<int> a(n);
	vector<int> cnt(200200);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}
	vector<int> dp(200200,-1);
	function<int(int)> dfs = [&](int x) {
		if(dp[x]!=-1)
			return dp[x];
		dp[x] = cnt[x];
		int mx = 0;
		for(int i=1 ; i*i<=x ; i++) {
			if(x % i) continue;
			if(cnt[i] > 0 && x != i)
				mx = max(mx, dfs(i));
			if(cnt[x/i] > 0 && x/i != x)
				mx = max(mx, dfs(x/i));
		}
		dp[x] += mx;
		return dp[x];
	};
	int mx = 0;
	for(int i=0 ; i<n ; i++) {
		mx = max(mx, dfs(a[i]));
	}
	cout << n - mx << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}