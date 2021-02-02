#include <bits/stdc++.h>
using namespace std;

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

vector<int> par(100100);

int find(int x) {
	if(par[x] == x) return x;
	return par[x] = find(par[x]);
}

void unite(int x, int y) {
	x = find(x); y = find(y);
	if(x>y) swap(x,y);
	par[y] = x;
	return;
}

struct cmp {
	bool operator() (pii x, pii y) {
		return x.ss < y.ss;
	}
};

void solve() {
	int n, m; cin >> n >> m;
	for(int i=0 ; i<100100 ; i++)
		par[i] = i;
	vector<vector<int>> G(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		unite(u, v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	int k; cin >> k;
	vector<int> need(k);
	for(int i=0 ; i<k ; i++) {
		cin >> need[i]; need[i]--;
	}
	for(int i=0 ; i<k ; i++) {
		if(find(need[i])!=find(need[0])) {
			cout << -1 << "\n";
			return;
		}
	}
	vector<vector<int>> dis(k, vector<int>(n, INF));
	for(int i=0 ; i<k ; i++) {
		queue<int> q;
		vector<bool> vis(n);
		q.push(need[i]); vis[need[i]] = 1;
		dis[i][need[i]] = 0;
		while(!q.empty()) {
			int cur = q.front(); q.pop();
			for(int nxt : G[cur]) {
				if(vis[nxt]) continue;
				vis[nxt] = 1;
				dis[i][nxt] = dis[i][cur] + 1;
				q.push(nxt);
			}
		}
	}
	vector<vector<int>> dp(pw(k), vector<int>(k, INF));
	for(int i=0 ; i<k ; i++) {
		dp[1<<i][i] = 1;	
	}
	for(int mask = 1 ; mask < pw(k) ; mask++) {
		for(int lastSeen = 0 ; lastSeen<k ; lastSeen++) {
			if(dp[mask][lastSeen] == INF) continue;
			for(int i=0 ; i<k ; i++) {
				if(mask & pw(i)) continue;
				int newMask = (mask|pw(i));
				dp[newMask][i] = min(dp[newMask][i], dp[mask][lastSeen] + dis[lastSeen][need[i]]);
			}
		}
	}
	int ans = INF;	
	int fullmask = pw(k) - 1;
	for(int i=0 ; i<k ; i++) 
		ans = min(ans, dp[fullmask][i]);

	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}