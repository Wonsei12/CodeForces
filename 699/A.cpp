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
	int px, py; cin >> px >> py;
	string s; cin >> s;
	int r = 0, u = 0, d = 0, l = 0;;
	for(int i=0 ; i<sz(s) ; i++) {
		if(s[i] == 'R') r++;
		if(s[i] == 'U') u++;
		if(s[i] == 'L') l++;
		if(s[i] == 'D') d++;
	}
	if(px > 0) {
		if(r < px) {
			cout << "NO\n";
			return;
		}
	} else if(px < 0) {
		px = -px;
		if(l < px) {
			cout << "NO\n";
			return;
		}
	}
	if(py > 0) {
		if(u < py) {
			cout << "NO\n";
			return;
		}
	} else if(py < 0) {
		if(d < -py) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main() {
	IOS;
	int t = 1; cin >> t;
	while(t--)
		solve();
}