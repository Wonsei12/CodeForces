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
	int n; cin >> n;
	string s; cin >> s;
	vector<int> val(10);
	for(int i=1 ; i<=9 ; i++)
		cin >> val[i];
	int sIdx = -1;
	for(int i=0 ; i<sz(s) ; i++) {
		if(s[i]-'0' < val[s[i]-'0']) {
			sIdx = i;
			break;
		}
	}
	if(sIdx == -1) {
		cout << s << "\n";
		return;
	}
	int eIdx = n-1;
	for(int i=sIdx ; i<sz(s) ; i++) {
		if(s[i]-'0' > val[s[i]-'0']) {
			eIdx = i - 1;
			break;
		}
	}
	for(int i=sIdx ; i<=eIdx ; i++) {
		s[i] = '0' + val[s[i]-'0'];
	}
	cout << s << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}