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

void solve() {
	int n; cin >> n;
	vector<vector<int>> G(n);
	for(int i=0 ; i<n-1 ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	vector<vector<int>> par(n, vector<int>(21));
	vector<int> dep(n);
	function<void(int, int, int)> dfs = [&](int v, int d, int p) {
		par[v][0] = p;
		dep[v] = d;
		for(int nxt : G[v]) {
			if(nxt == p) continue;
			dfs(nxt, d+1, v);
		}
	};
	dfs(0,0,0);
	for(int x=1 ; x<21 ; x++) {
		for(int v=0 ; v<n ; v++) {
			par[v][x] = par[par[v][x-1]][x-1];
		}
	}
	function<int(int, int)> LCA = [&](int x, int y) {
		if(dep[x] > dep[y]) 
			swap(x,y);
		for(int i=20 ; i>=0 ; i--) {
			if(dep[y]-dep[x] >= pw(i))
				y = par[y][i];
		}
		if(x==y)
			return x;
		for(int i=20 ; i>=0 ; i--) {
			if(par[x][i] != par[y][i]) {
				x = par[x][i];
				y = par[y][i];
			}
		}
		return par[x][0];
	};
	int q; cin >> q;
	while(q--) {
		int a, b, e; cin >> a >> b >> e; a--, b--;
		int lca = LCA(a,b);
		int lcatoA = dep[a] - dep[lca];
		int lcatoB = dep[b] - dep[lca];
		int dis = 0, c = 0;;
		if(e <= lcatoA) {
			dis = e;
			c = a;
		} else {
			e -= lcatoA;
			lcatoB -= e;
			dis = lcatoB;
			c = b;
		}
		int idx=0;
		while(dis > 0) {
			if(dis&1) {
				c = par[c][idx];
			}
			dis /= 2;
			idx += 1;
		}
		cout << c + 1 << "\n";
	}
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}