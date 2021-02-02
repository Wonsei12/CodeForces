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
	vector<pair<ll, ll>> a(n);
	for(int i=0 ; i<n ; i++)
		cin >> a[i].ff >> a[i].ss;
	vector<bool> vis(n);
	vis[0] = 1;
	vector<int> ans;
	ans.push_back(0);
	int cur = 0;

	auto dis = [](pair<ll, ll> a, pair<ll, ll> b) {
		ll x = a.ff - b.ff;
		ll y = a.ss - b.ss;
		return 0LL + x*x + y*y;
	};

	for(int i=0 ; i<n-1 ; i++) {
		ll mx = 0;
		ll mxIdx = -1;
		for(int j=0 ; j<n ; j++) {
			if(cur == j) continue;
			if(vis[j]) continue;	
			if(mx < dis(a[cur], a[j])) {
				mx = dis(a[cur], a[j]);
				mxIdx = j;
			}
		}
		vis[mxIdx] = 1;
		ans.push_back(mxIdx);
		cur = mxIdx;
	}	
	for(auto x : ans) 
		cout << x+1 << " ";
	cout << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}