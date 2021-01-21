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

class SegmentTree {
public:
	vector<ll> seg;
	int n;
	SegmentTree(int n) {
		seg.resize(4 * n + 5);
		this->n = n;
	}
	ll upd_(int idx, int l, int r, int pos, ll val) {
		if (pos < l || pos > r) return seg[idx];
		if (pos == l && pos == r) return seg[idx] += val;
		int mid = (l + r) / 2;
		return seg[idx] = upd_(idx * 2, l, mid, pos, val) +
				upd_(idx * 2 + 1, mid + 1, r, pos, val);
	}
	ll calc_(int idx, int l, int r, int tl, int tr) {
		if (tl > tr) return 0;
		if (tl == l && tr == r) return seg[idx];
		int mid = (l + r) / 2;
		return calc_(idx * 2, l, mid, tl, min(tr, mid)) +
			calc_(idx * 2 + 1, mid + 1, r, max(mid + 1, tl), tr);
	}
	ll find_(int idx, int l, int r, ll rank) {
		if(l==r) return l;
		int mid = (l+r)/2;
		if(seg[idx*2]>=rank) return find_(idx*2,l,mid,rank);
		else return find_(idx*2+1,mid+1,r,rank-seg[idx*2]); 
	}
	void upd(int pos, ll val) {
		upd_(1, 0, n - 1, pos, val);
	}
	ll calc(int l, int r) {
		return calc_(1, 0, n - 1, l, r);
	} 
	ll find(ll rank) {
		return find_(1, 0, n-1, rank);
	}
};

void solve() {
	int n, q; cin >> n >> q;
	vector<int> a(n);
	SegmentTree st(1000010);
	for(int i=0 ; i<n ; i++) {
		cin >> a[i];
		st.upd(a[i],1);
	}
	while(q--) {
		int t; cin >> t;
		if(t>0) {
			st.upd(t,1);
		} else {
			int l = 1, r = 1e6; 
			int ans = 0;
			while(l<=r) {
				int mid = (l+r)/2;
				if(st.calc(1,mid) >= -t) {
					ans = mid;
					r = mid - 1;
				} else 
					l = mid + 1;
			}
			st.upd(ans,-1);
		}
	}
	for(int i=1 ; i<=n ; i++) {
		if(st.calc(i,i)==1) {
			cout << i << "\n";
			return;
		}
	}
	cout << 0 << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}