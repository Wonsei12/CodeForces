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
	int n, m; cin >> n >> m;
	vector<pii> a(m), b(m);
	for(int i=0 ; i<m ; i++) 
		cin >> a[i].ff >> a[i].ss;
	sort(a.begin(),a.end());
	for(int i=0 ; i<m ; i++) 
		cin >> b[i].ff >> b[i].ss;
	sort(b.begin(),b.end());
	for(int i=0 ; i<m ; i++) {
		int tarX = i, tarY = 
	}
}

int main() {
	IOS;
	int t = 1; cin >> t;
	while(t--)
		solve();
}