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

ll gcd(ll a, ll b) {
	if(b==0)
		return a;
	return gcd(b, a%b);
}

void solve() {
	ll p, q, b; cin >> p >> q >> b;
	ll z = gcd(p, q);
	q /= z;
	while(1) {
		ll z2 = gcd(q, b);
		if(z2 == 1) {
			break;
		}
		while(q % z2 == 0)
			q /= z2;
	}
	if(q == 1) 
		cout << "Finite\n";
	else
		cout << "Infinite\n";
}

int main() {
	IOS;
	int t = 1; cin >> t;
	while(t--)
		solve();
}