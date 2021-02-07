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

int main() {
	IOS;
	int h, w; cin >> h >> w;
	vector<string> G(h);
	for(int i=0 ; i<h ; i++) {
		cin >> G[i];
	}
	int ans = 0;
	for(int i=1 ; i<h ; i++) {
		for(int j=1 ; j<w ; j++) {
			int cnt = 0;
			for(int k=-1 ; k<=0 ; k++){
				for(int l=-1 ; l<=0 ; l++) {
					if(G[i+k][j+l] == '.') cnt++;
				}
			}
			if(cnt == 1 || cnt == 3) {
				ans += 1;
			}
		}
	}
	cout << ans << "\n";
}