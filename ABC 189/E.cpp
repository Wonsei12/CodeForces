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
	for(int i=0 ; i<n ; i++)
		cin >> a[i].ff >> a[i].ss;
	int m; cin >> m;
	vector<pii> cps(m+1);
	vector<int> ops(m+1);
	int right = 0;
	for(int i=1 ; i<=m ; i++) {
		int op; cin >> op;
		if(op == 1) {
			right += 1;
			right %= 4;
			ops[i] = right;
			cps[i] = cps[i-1];
		} else if(op == 2) {
			right += 3;
			right %= 4;
			ops[i] = right;
			cps[i] = cps[i-1];
		} else if(op == 3) {
			int p; cin >> p;
			cps[i].ff = cps[i-1].ff + 2 * (p - cps[i-1].ff);
			ops[i] = ops[i-1];
		} else if(op == 4) {
			int p; cin >> p;
			cps[i].ss = cps[i-1].ss + 2 * (p - cps[i-1].ss);
			ops[i] = ops[i-1];
		}
	}
	int q; cin >> q;
	while(q--) {
		int a, b; cin >> a >> b;
		if(cps[i-1])
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}