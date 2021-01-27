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
ll F[2020], rF[2020];
void init() {
	F[0] = 1;
	for(int i=1 ; i<=2000 ; i++) {
		F[i] = mult(F[i-1], i);
	}
	rF[2000] = rev(F[2000]);
	for(int i=2000 ; i>0 ; i--) {
		rF[i-1] = mult(rF[i], i);
	}
}
ll nCr(ll n, ll r) {
	ll x = F[n];
	ll y = rF[n-r];
	ll z = rF[r];
	return mult(x,mult(y,z));
} 

void solve() {
	int n, m; cin >> n >> m;
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	sort(a.rbegin(),a.rend());
	int last = a[m-1];
	int cnt = 0, realcnt = 0;
	for(int i=0 ; i<m ; i++) {
		if(a[i] == last) 
			cnt ++;
	}
	for(int i=0 ; i<n ; i++) {
		if(a[i] == last) 
			realcnt ++;
	}
	cout << nCr(realcnt, cnt) << "\n";
}

int main() {
	IOS;
	init();
	int t; cin >> t;
	while(t--)
		solve();
}