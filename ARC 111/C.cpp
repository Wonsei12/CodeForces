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
	vector<pii> a(n);
	vector<int> b(n),pm(n),who(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].ff;
		a[i].ss = i;
	}
	for(int i=0 ; i<n ; i++) 
		cin >> b[i];
	for(int i=0 ; i<n ; i++) {
		cin >> pm[i]; pm[i] -= 1;
		who[pm[i]]=i;
		if(a[i].ff<=b[pm[i]] && pm[i]!=i) {
			cout << -1 << "\n";
			return;
		}
	}
	sort(all(a));
	vector<pii> ans;
	for(int i=0 ; i<n ; i++) {
		int cur = a[i].ss;
		if(pm[cur]==cur)
			continue;
		int nxt = who[cur];
		ans.push_back({cur,nxt});
		swap(who[cur],who[pm[cur]]);
		pm[nxt] = pm[cur];
		pm[cur] = cur;
	}
	cout << sz(ans) << "\n";
	for(auto x : ans) {
		cout << x.ff+1 << " " << x.ss+1 << "\n"; 
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}