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
	int n; cin >> n;
	int k; cin >> k;
	vector<int> a(n);
	for(auto &x : a) cin >> x;
	sort(a.rbegin(),a.rend());
	int ans = 0;
	int idx=-1;
	for(int i=0 ; i<n ; i++) {
		if(a[i] >= k) ans ++;
		else {
			idx=i;
			break;
		}
	}
	if(idx==-1) cout << ans << "\n";
	else {
		for(int i=idx,idx2=n-1 ; i>=0 ; ) {
			if(idx2<=i) break;
			if(a[i]+a[idx2]>=k) {
				ans+=1;
				i+=1;
				idx2-=1;
			} else
				idx2-=1;
		}
		cout << ans << "\n";
	}
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}