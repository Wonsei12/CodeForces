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
	int minus = 0, plus = 0, zero = 0;
	vector<pii> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i].ff; a[i].ss = i;
		if(a[i].ff >= 0)
			a[i].ff = -a[i].ff - 1; 
	}
	sort(a.begin(),a.end()); // -5
	if(n%2==1) {
		a[0].ff = -a[0].ff - 1;
	}
	vector<int> ans(n);
	for(auto x : a) {
		ans[x.ss] = x.ff;
	}
	for(auto x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}