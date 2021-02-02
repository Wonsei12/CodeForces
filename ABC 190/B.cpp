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
	int n, s, d; cin >> n >> s >> d;
	bool ok = false;
	while(n--) {
		int x, y; cin >> x >> y;
		if(x >= s) continue;
		if(y <= d) continue;
		ok = true;
	}
	if(ok) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}