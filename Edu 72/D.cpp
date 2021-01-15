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
	int n, m; cin >> n >> m;
	vector<int> ans(m);
	vector<vector<int>> G(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		if(u<v)
			ans[i]=1;
		else
			ans[i]=2;
	}
	vector<int> vis(n);
	bool cyc = false;
	function<void(int)> dfs = [&](int cur) {
		vis[cur]=1;
		for(int nxt : G[cur]) {
			if(cyc)
				return;
			if(vis[nxt]==1) {
				cyc = true;
				return;
			} else if(vis[nxt]==0) {
				dfs(nxt);
			}
		}
		vis[cur]=2;
	};
	for(int i=0 ; i<n ; i++) {
		if(!vis[i]) 
			dfs(i);
		if(cyc)
			break;
	}
	if(cyc) {
		cout << 2 << "\n";
		for(auto x : ans) {
			cout << x << " ";
		}
		cout << "\n";
	}
	else {
		cout << 1 << "\n";
		for(auto x : ans) {
			cout << 1 << " ";
		}
		cout << "\n";
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}