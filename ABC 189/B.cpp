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
	int n;
	ll X; cin >> n >> X; X *= 100;
	vector<pair<ll, ll>> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].ff >> a[i].ss;
	}
	ll cur = 0;
	for(int i=0 ; i<n ; i++) {
		cur += a[i].ff * a[i].ss;
		if(cur > X) {
			cout << i+1 << '\n';
			return;
		}
	}
	cout << -1 << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}