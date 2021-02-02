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
ll F[100100], rF[100100];
ll nCr(ll n, ll r) {
	ll a = F[n];
	ll b = rF[r];
	ll c = rF[n-r];
	return mult(a,mult(b,c));
}
ll nHr(ll n, ll r) {
	return nCr(n+r-1, r);
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	int rec = 0;
	for(auto x : s) {
		if(x=='-') continue;
		if(x-'0'<rec) {
			cout << 0 << "\n";
			return;
		}
		rec = x-'0';
	}
	ll ans = 1;
	int bincan = 0;
	rec = 1;
	for(int i=0 ; i<n ; i++) {
		if(s[i]=='-') bincan +=1;
		else {
			int cur = s[i]-'0';
			ans=mult(ans,nHr(cur-rec+1,bincan));
			bincan = 0;
			rec = cur;
		}
	}
	int cur=9;
	ans=mult(ans,nHr(cur-rec+1,bincan));
	cout << ans << "\n";
}

void init() {
	F[0] = 1;
	for(int i=1 ; i<100100 ; i++) {
		F[i] = mult(F[i-1],i);
	}
	rF[100099] = rev(F[100099]);
	for(int i=100099 ; i>0 ; i--) {
		rF[i-1] = mult(rF[i], i);
	}
	assert(rF[0] == 1);
}

int main() {
	IOS;
	init();
	int t; cin >> t;
	while(t--)
		solve();
}