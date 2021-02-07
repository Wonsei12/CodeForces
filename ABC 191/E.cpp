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

struct cmp
{
	bool operator() (pair<int, ll> a, pair<int, ll> b) {
		return a.ss > b.ss;
	} 
};

int main() {
	IOS;
	int n, m; cin >> n >> m;
	vector<vector<pair<int, ll>>> G(n);
	for(int i=0 ; i<m ; i++) {
		int u, v; ll d; cin >> u >> v >> d; u--, v--;
		G[u].push_back({v,d});
	}
	for(int i=0 ; i<n ; i++) {
		sort(all(G[i]));
	}
	for(int i=0 ; i<n ; i++) {
		vector<ll> dis(n, LLINF);
		ll mn = LLINF;
		priority_queue<pair<int, ll>, vector<pair<int, ll>>, cmp> pq;
		pq.push({i,0});
		while(!pq.empty()) {
			int curNode = pq.top().ff;
			ll curDis = pq.top().ss;
			pq.pop();
			if(curDis > dis[curNode]) continue;
			for(auto nxt : G[curNode]) {
				int nxtNode = nxt.ff;
				ll roadDis = nxt.ss;
				if(nxtNode == i) {
					mn = min(mn, roadDis + curDis);
					continue;
				} else if(dis[nxtNode] > curDis + roadDis) {
					dis[nxtNode] = curDis + roadDis;
					pq.push({nxtNode, dis[nxtNode]});
				}
			} 
		}
		if(mn == LLINF) cout << -1 << "\n";
		else cout << mn << "\n";
	}
}