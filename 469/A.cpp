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

void solve() {
	string s; cin >> s;
	int bad = 0, good = 0;
	for(auto x : s) {
		if(x=='0') bad += 1;
		else good += 1;
	}
	ll dif = bad - good; 
	if(dif <= 0) {
		cout << "-1\n";
		return;
	} 
	vector<vector<int>> ans;
	queue<int> zero, one;
	int idx = 0;
	for(int i=0 ; i<sz(s) ; i++) {
		if(s[i] == '0') {
			if(sz(one)) {
				int x = one.front(); one.pop();
				ans[x].push_back(i);
				zero.push(x);
			} else {
				ans.push_back(vector<int>{});
				ans[idx].push_back(i);
				zero.push(idx);
				idx ++;
			}
		} else {
			if(sz(zero)) {
				int x = zero.front(); zero.pop();
				ans[x].push_back(i);
				one.push(x);
			} else {
				cout << -1 << "\n";
				return;
			}
		}
	}
	if(sz(one)) {
		cout << -1 << "\n";
		return;
	}
	cout << sz(ans) << "\n";
	for(int i=0 ; i<sz(ans) ; i++) {
		cout << sz(ans[i]) << " ";
		for(auto x : ans[i]) {
			cout << x + 1 << " ";
		}
		cout << "\n";
	}
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}