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

int gcd(int a, int b) {
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve() {
	int n; cin >> n;
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
	}
	vector<vector<bool>> good(n, vector<bool>(n));
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(gcd(a[i],a[j]) > 1) 
				good[i][j] = 1;
		}
	}
	vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, -1)));
	// dp[L][R][0] -> L-1을 부모로 갖는 [L, R]구간의 서브트리가 가능
	// dp[L][R][1] -> R+1을 부모로 갖는 [L, R]구간의 서브트리가 가능

	function<int(int,int,int)> ok = [&](int l, int r, int w) {
		int& ret = dp[l][r][w];
		if(ret != -1) return ret;
		if(l == r) {
			if(w==0) {
				if(l-1 < 0) return ret = 0;
				if(good[l-1][l] > 1) return ret = 1;
				else return ret = 0;
			} else {
				if(r+1 > n-1) return ret = 0;
				if(good[r][r+1]) return ret = 1;
				else return ret = 0;
			}
		}
		ret = 0;
		for(int i=l ; i<=r ; i++) {
			
		}
		return ret;
	};
	if(ok(1,n,0)==1) cout << "Yes\n";
	else cout << "No\n";

	return;
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}