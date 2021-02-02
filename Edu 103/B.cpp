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
	ll k; cin >> k;
	vector<ll> a(n);
	for(int i=0 ; i<n ; i++)
		cin >> a[i];
	ll sum = 0, ans = 0;
	sum += a[0];
	for(int i=1 ; i<n ; i++) {
		ll need = max(0LL,a[i] * 100 - k * sum);
		ll realneed = (need + k - 1) / k;
		sum += a[i];
		ans = max(realneed, ans);
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1; cin >> t;
	while(t--)
		solve();
}