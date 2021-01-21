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
#define mask second
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
	vector<int> a(n), b(n);
	for(int i=0 ; i<n ; i++) 
		cin >> a[i];
	for(int i=0 ; i<n ; i++)
		cin >> b[i];
	vector<vector<int>> dp(pw(n), vector<int>(51, INF));
	auto pc = [](int mask) -> int {
		int cnt = 0;
		while(mask > 0) {
			if(mask&1)
				cnt += 1;
			mask /= 2;
		}
		return cnt;
	};
	int x, y;
	for(ll mask=1 ; mask<pw(n) ; mask++) {
        int cnt=0,cnt1=0;
        cnt = pc(mask);
        for(int i=0 ; i<n ; i++) {
            if(mask&pw(i)) {
                cnt1++;
                if((cnt-i+1)%2==0)
                    x=a[i];
                else
                    x=b[i];
                if(cnt==1) {
                    dp[mask][i]=0;
                    continue;
               	}
            	for(int j=0 ; j<n ; j++) {
               	    if(i==j)
                  		continue;
                	if(mask&pw(j)) {
                   		if((cnt-j)%2==0)
                        	y=a[j];
                    	else
                        	y=b[j];
                    	if(x>=y)
                        	dp[mask][i]=min(dp[mask][i],dp[mask-(pw(i))][j]+cnt-cnt1);
               		}
           		}
            }
        }
    }
    int ans = INF;
    for(int i=0 ; i<n ; i++) 
    	ans = min(ans, dp[pw(n)-1][i]);
    if(ans==INF)
    	cout << -1 << "\n";
    else
    	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}