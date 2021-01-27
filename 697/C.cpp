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
	int n, m, k; cin >> n >> m >> k;
	vector<pair<ll, ll>> ps(k);
	vector<ll> cnta(n+1),cntb(m+1);
	for(int i=0 ; i<k ; i++) {
		cin >> ps[i].ff; 
	}
	for(int i=0 ; i<k ; i++) {
		cin >> ps[i].ss;
		ps[i].ff--; ps[i].ss--;
		cnta[ps[i].ff]+=1;
		cntb[ps[i].ss]+=1;
	}
	ll ans = 0;
	for(int i=0 ; i<k ; i++) {
		ans += (k - 1) - (cnta[ps[i].ff] - 1) - (cntb[ps[i].ss] - 1);
	}
	cout << ans / 2 << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}