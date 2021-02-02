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

vector<int> tree[1000010];
vector<int> arr;

void update(int bucket, int node, int start, int end, int x){
	if(node<start || end<node) return;
	tree[bucket].push_back(x);
	if(start != end){
		update(bucket*2, node, start, (start+end)/2, x);
		update(bucket*2+1, node, (start+end)/2+1, end, x);
	}
}

int get(int node, int start, int end, int left, int right, int x){
	if(left>end || right<start) return 0;
	if(left<=start && end<=right) return tree[node].end() - upper_bound(tree[node].begin(), tree[node].end(), x);
	int mid = (start+end)>>1;
	return get(node*2, start, mid, left, right, x) + get(node*2+1, mid+1, end, left, right, x);
}

void solve() {

	int n; cin >> n;
	arr.resize(n+10);
	for(int i=1 ; i<=n ; i++) cin >> arr[i];
	for(int i=1 ; i<=n ; i++) arr[i] = min(arr[i], n);
	for(int i=1 ; i<=n ; i++) {
		update(1,i,1,n,arr[i]);
	}
	for(int i=0 ; i<500010 ; i++) {
		sort(all(tree[i]));
	}
	ll ans = 0;
	for(int i=1 ; i<=n ; i++) {
		int danger = arr[i] - i;
		if(danger <= 0) continue;
		//i+1 ~ i+danger까지 i 이상인 갯수만큼 제거됨.
		if(i+1 > n) continue;

		ans += get(1,1,n,i+1,min(n,i+danger),i-1);
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}