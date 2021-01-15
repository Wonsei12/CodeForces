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
	int n, x; cin >> n >> x;
	vector<ll> damage(n);
	vector<ll> heal(n);
	ll mxDamage = 0;
	ll mxInstakill = 0;
	ll mxDamageZ;
	for(int i=0 ; i<n ; i++) {
		cin >> damage[i] >> heal[i];
		mxInstakill = max(mxInstakill, damage[i]);
		if(heal[i] < damage[i]) {
			mxDamage = max(mxDamage, damage[i] - heal[i]);
			mxDamageZ = damage[i];
		}
	}
	if(mxInstakill >= x) {
		cout << 1 << "\n";
		return;
	}
	if(mxDamage == 0) {
		cout << -1 << "\n";
		return;
	}
	ll needToDamage = x - mxInstakill;
	ll needHits = (needToDamage + mxDamage - 1) / mxDamage - 1;
	if(needHits * mxDamage + mxDamageZ >= x) {
		cout << needHits + 1 << "\n";
		return;
	} 
	needHits += 1;
	cout << needHits + 1 << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}