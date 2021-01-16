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
	int n, k; cin >> n >> k;
	vector<int> cnt(n+2);
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		cnt[a[i]] += 1;
	}
	int ans = 0;
	while(1) {
		int mx = 0, mn = INF;
		for(int i=0 ; i<=n ; i++) {
			if(cnt[i]==0) {
				mx = i;
				break;
			}
			mn = min(mn,cnt[i]);
		}
		if(mx==0)
			break;
		for(int j=0 ; j<mx ; j++) 
			cnt[j] -= mn;
		ans += min(mn, k) * mx;
		k-=mn;
		if(k<=0)
			break;
	}

	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}