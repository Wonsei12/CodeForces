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
	// 홀수 사이클이 생기게 하지 말자? 
	int n; cin >> n;
	for(int i=n-1 ; i>=1 ; i--) {
		for(int j=1 ; j<=i ; j++) {
			cout << i << " ";
		}
		cout << "\n";
	}
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}