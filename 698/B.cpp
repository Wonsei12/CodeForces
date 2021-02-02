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

class SegmentTreeWithLazy{
public:
    vector<int> segtree,lazy;
    int n;
    
    SegmentTreeWithLazy(int n){
        segtree.resize(1<<((int)ceil(log2(n))+1));
        lazy.resize(1<<((int)ceil(log2(n))+1));
        this->n=n;
    }

    void lazy_propagation(int ns, int ne, int pos)
    {
        if(lazy[pos]!=0){
            segtree[pos]=lazy[pos]*(ne-ns+1);
            if(ns!=ne){
                lazy[pos*2]=lazy[pos];
                lazy[pos*2+1]=lazy[pos];
            }
            lazy[pos]=0;
        }
    }
    
    void update(int ns, int ne, int s, int e, int pos, int value)
    {
        lazy_propagation(ns, ne, pos);
        if(e<ns || s>ne) return;
        if(s<=ns && ne<=e){
            lazy[pos]=value;
            lazy_propagation(ns, ne, pos);
            return;
        }
        int mid=(ns+ne)/2;
        update(ns,mid,s,e,pos*2,value);
        update(mid+1,ne,s,e,pos*2+1,value);
        segtree[pos]=segtree[pos*2]+segtree[pos*2+1];
    }
    
    int query(int ns, int ne, int s, int e, int pos)
    {
        lazy_propagation(ns,ne,pos);
        if(e<ns || s>ne) return 0;
        if(s<=ns && ne<=e) return segtree[pos];
        int mid=(ns+ne)/2;
        return query(ns,mid,s,e,pos*2)+query(mid+1,ne,s,e,pos*2+1);
    }
    
    void update_simple(int s, int e, int value)
    {
        update(0,n-1,s,e,1,value);
    }
    
    int query_simple(int s, int e)
    {
        return query(0,n-1,s,e,1);
    }
};

void solve() {
	int n, q; cin >> n >> q;
	string s1, s2; cin >> s1 >> s2;
	vector<pii> qs;
	SegmentTreeWithLazy st(n);
	for(int i=0 ; i<q ; i++) {
		int l, r; cin >> l >> r; l--, r--;
		qs.push_back({l,r});
	}
	for(int i=0 ; i<sz(s2) ; i++) {
		if(s2[i]=='0')
			st.update_simple(i,i,1);
		else
			st.update_simple(i,i,2);
	}
	
	for(int i=q-1 ; i>=0 ; i--) {
		int totlen = qs[i].ss-qs[i].ff+1;
		int totsum = st.query_simple(qs[i].ff,qs[i].ss);
		//2의 갯수는 totsum - totlen개
		int ones = totsum - totlen;
		if(totlen % 2 == 0 && totlen/2 == ones) {
			cout << "NO\n";
			return;
		}
		if(ones * 2 > totlen) {
			st.update_simple(qs[i].ff,qs[i].ss,2);
		} else {
			st.update_simple(qs[i].ff,qs[i].ss,1);
		}

	}
	for(int i=0 ; i<n ; i++) {
		if(st.query_simple(i,i)!=s1[i]-'0'+1) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}