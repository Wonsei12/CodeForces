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
	int z=0;
	int a, b, c; cin >> a >> b >> c;
	for(int k=0 ; ; k++) {
		if(a < k || b < 2 * k) break;
		int ans = 3 * k;
		int tb = b - 2 * k;
		z = max(z,ans+ 3 * min(c/2,tb));
	}
	cout << z << "\n";
}

int main() {
	IOS;
	int t = 1; cin >> t;
	while(t--)
		solve();
}