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
	int n,m,k; cin >> n >> m >> k;
	map<string, int> mp;
	vector<string> a(n);
	vector<vector<int>> G(n);
	for(int i=0 ; i<n ; i++) {
		string s; cin >> s;
		mp[s] = i+1;
		a[i] = s;
	}
	vector<int> deg(n);
	for(int i=0 ; i<m ; i++) {
		string s; cin >> s;
		int id; cin >> id; id--;
		vector<int> possible;
		bool valid = false;
		for(int mask = 0 ; mask < pw(k) ; mask++) {
			string t = s;
			int t2 = mask;
			int idx = 0;
			while(t2 > 0) {
				if(t2&1) {
					t[idx] = '_';
				}
				idx += 1;
				t2 /= 2;
			}
			if(mp[t] == 0) continue;
			int node = mp[t] - 1;
			possible.push_back(node);
			if(node == id)
				valid = true;
 		}
 		if(!valid) {
 			cout << "NO\n";
 			return;
 		}
 		for(int x : possible) {
 			if(x==id) continue;
 			G[id].push_back(x);
 			deg[x] += 1;
 	//		debug(id, x);
 		}
	}
	bool cycle = false;
	vector<int> vis(n);
	function<void(int)> iscycle = [&](int v) {
		vis[v] = 1;
		for(int nxt : G[v]) {
			if(vis[nxt] == 1) {
				cycle = true; return;
			}
			else if(vis[nxt] == 2) 
				continue;
			else 
				iscycle(nxt);
			if(cycle)
				return;
		}
		vis[v] = 2;
	};
	for(int i=0 ; i<n ; i++) {
		if(!vis[i]) {
			iscycle(i);
			if(cycle) break;
		}
	}
	if(cycle) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	vector<int> ans;
	vector<bool> vis2(n);
	queue<int> q;
	for(int i=0 ; i<n ; i++) {
		if(deg[i] == 0) {
			q.push(i);
			vis2[i] = 0;
			ans.push_back(i+1);
		}	
	}
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		for(int nxt : G[cur]) {
			if(vis2[nxt]) continue;
			deg[nxt] -= 1;
			if(deg[nxt] == 0) {
				vis2[nxt] = 1;
				q.push(nxt);
				ans.push_back(nxt+1);
			}
		}
	}
	for(auto x : ans ){
		cout << x << " ";
	}
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}