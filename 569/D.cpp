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
	if(n==1 && m==1) {
		cout << 1 << " " << 1 << "\n";
		return; 
	}
	int sm = 1, em = m;
	vector<pii> ans;
	if(m%2 == 0) {
		while(1) {
			for(int i=0 ; i<n ; i++) {
				ans.push_back({i+1,sm});
				ans.push_back({n-i,em});
			}
			sm += 1; em -= 1;
			if(sm >= em)
				break;
		}
	} else {
		while(1) {
			if(sm == em)
				break;

			for(int i=0 ; i<n ; i++) {
				ans.push_back({i+1,sm});
				ans.push_back({n-i,em});
			}
			sm += 1; em -= 1;
		}
		int si,ei;
		for(si=1,ei=n ; si<ei ; si++,ei--) {
			ans.push_back({si, sm});
			ans.push_back({ei, sm});
		}
		if(si==ei)
			ans.push_back({si, sm});
	}
	assert(sz(ans) == n * m);
	for(auto x : ans) {
		cout << x.ff << " " << x.ss << "\n";
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}