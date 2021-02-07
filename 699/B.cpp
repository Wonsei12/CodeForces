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
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	int ans = 0;
	while(k--) {
		for(int i=0 ; i<n ; i++) {
			if(i == n-1) {
				cout << "-1\n";
				return;
			}
			if(a[i] >= a[i+1]) continue;
			else {
				a[i] ++; ans = i;break;
			}
		}
	}
	cout << ans + 1 << "\n";
}

int main() {
	IOS;
	int t = 1; cin >> t;
	while(t--)
		solve();
}