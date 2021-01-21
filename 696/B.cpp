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

vector<bool> sieve(50000);
vector<int> primes;
void init() {
	for(int i=2 ; i<=49999 ; i++) {
		if(!sieve[i]) {
			primes.push_back(i);
			for(int j=i*2 ; j<=49999 ; j+=i) {
				sieve[j] = 1;
			}
		}
	}
}
void solve() {
	int d; cin >> d;
	ll ans = 1;
	int idx1 = lower_bound(primes.begin(),primes.end(),d+1) - primes.begin();
	int firstPrime = primes[idx1];
	int idx2 = lower_bound(primes.begin(),primes.end(),firstPrime + d) - primes.begin();
	ans *= (ll)primes[idx1];
	ans *= (ll)primes[idx2];
	cout << ans << "\n"; 
}

int main() {
	IOS;
	init();
	int t; cin >> t;
	while(t--)
		solve();
}