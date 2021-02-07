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

ll add(ll x, ll y) {
	x+=y; x%=MOD;
	return x;
}
ll sub(ll x, ll y) {
	x-=y; x%=MOD; if(x<0) x+=MOD;
	return x;
}
ll mult(ll x, ll y) {
	return (x*y)%MOD;
}
ll bin_pow(ll x, ll p) {
	if(p==0) return 1;
	if(p&1) return mult(x,bin_pow(x,p-1));
	return bin_pow(mult(x,x),p/2);
}
ll rev(ll x) {
	return bin_pow(x,MOD-2);
}

void solve() {
	ll n, m; cin >> n >> m;
//	(2^n)^m - mC1 * (2^n-1)^m + mC2 (2^n-2)^m
	//(2^n - 1) ^ m 
	ll z = bin_pow(2,m);
	z -= 1; if(z<0) z += MOD;
	ll y = bin_pow(z,n);
	cout << y << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}