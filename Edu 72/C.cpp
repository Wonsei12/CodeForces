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
	string s; cin >> s;
	int n = sz(s);
	reverse(s.begin(),s.end());
	s+='a';
	reverse(s.begin(),s.end());
	int rec = 0;
	vector<int> recentOne(n+1);
	for(int i=1 ; i<=n ; i++) {
		recentOne[i] = i - rec - 1;
		if(s[i]=='1')
			rec = i;
	}
	int ans = 0;
	for(int i=1 ; i<=n ; i++) {
		ll pow = 1;
		ll val = 0;
		ll curLen = 1;
		for(int j=i ; j>=1&&i-j<=20 ; j--) {
			val += (s[j]=='1') * pow;
			pow *= 2;
			if(s[j]=='1' && val!=0 && recentOne[j] >= val - curLen) {
				ans += 1;
			}
			curLen += 1;
		}
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}