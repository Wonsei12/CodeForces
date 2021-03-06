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
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve() {
	int n; ll k; cin >> n >> k;
	vector<ll> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	sort(all(a));
	vector<ll> dis;
	for(int i=0 ; i<n-1 ; i++) {
		dis.push_back(a[i+1]-a[i]);
	}
	ll g = dis[0];
	for(int i=1 ; i<sz(dis) ; i++) {
		g = gcd(g, dis[i]);
	} 
	if((k-a[0])%g==0)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}