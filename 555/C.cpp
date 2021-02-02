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
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	int l=0, r=n-1;
	int rec = -1;
	string ans = "";
	while(l <= r) {
		if(a[l] < rec && a[r] < rec) break;
		if(a[l] > a[r]) {
			if(a[r] > rec) {
				ans += "R";
				rec = a[r];
				r--;
			} else {
				ans += "L";
				rec = a[l];
				l++;
			}
		} else {
			if(a[l] > rec) {
				ans += "L";
				rec = a[l];
				l++;
			} else {
				ans += "R";
				rec = a[r];
				r--;
			}
		}
	}
	cout << sz(ans) << "\n";
	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}