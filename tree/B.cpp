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
	vector<vector<int>> G(n);
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int mx = -1, mxIdx = -1;
	function<void(int, int, int)> dfs = [&](int cur, int dep, int par) {
		if(mx < dep) {
			mxIdx = cur;
			mx = dep;
		}
		for(int nxt : G[cur]) {
			if(nxt == par) continue;
			dfs(nxt, dep+1, cur);
		}
	};
	dfs(0,0,-1);
	int d1 = mxIdx;
	dfs(d1,0,-1);
	int d2 = mxIdx;
	vector<int> dis(n), dis2(n);
	vector<bool> vis(n);
	queue<int> q;
	dis[d1]=0; vis[d1]=1; q.push(d1);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int nxt : G[cur]) {
			if(vis[nxt]) continue;
			vis[nxt] = 1;
			dis[nxt] = dis[cur] + 1;
			q.push(nxt);
		}
	}
	vis = vector<bool>(n);
	dis2[d2]=0; vis[d2]=0; q.push(d2);
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int nxt : G[cur]) {
			if(vis[nxt]) continue;
			vis[nxt] = 1;
			dis2[nxt] = dis2[cur] + 1;
			q.push(nxt);
		}
	}
	for(int i=0 ; i<n ; i++) {
		int mxDis = max(dis[i], dis2[i]);
		if(mxDis == mx) {
			cout << mx + 1 << "\n";
		} else {
			cout << mx << "\n";
		}
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}