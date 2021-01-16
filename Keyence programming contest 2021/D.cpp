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
const ll MOD = 998244353LL;
const long double PI = acos(-1.0);

int popcount(int x) {
	int cnt = 0;
	while(x>0) {
		if(x&1)
			cnt += 1;
		x/=2;
	}
	return cnt;
}

void solve() {
	int n; cin >> n;
	cout << (1<<n) - 1<< "\n";
	int x=1<<(n-1) ;
	for(int i=1 ; i<=(1<<n)-1 ; i++) {
		string s = "";
		for(int j=0 ; j<(1<<n) ; j++) {
			s+="A";
		}
		for(int j=0 ; j<(1<<n) ; j++) {
			if(popcount(i&j)&1)
				s[j]='B'; 
		}
		cout << s << "\n";
	}
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}