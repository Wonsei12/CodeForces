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
	int n, m; cin >> n >> m;
	vector<vector<int>> a(n, vector<int>(m));
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			cin >> a[i][j];
			if((i+j)%2!=a[i][j]%2)
				a[i][j] += 1;
		}
	}
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<m ; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}