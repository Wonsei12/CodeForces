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
	int ans = 0;
	ll n; cin >> n;
	n *= 2LL;
	for(ll i=1 ; i*i<=n ; i++) {
		if(n%i) continue;
		ll x = n / i;
		x += 1;
		x -= i;
		if(x % 2 == 0) {
			ans ++;
		}
		if(n/i==i) continue;
		x = i;
		x += 1;
		x -= n/i;
		if(x % 2 == 0) {
			ans ++;
		}
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}