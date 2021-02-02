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

// Copied from Gennady-Korotkevich's template

#define LOCAL

template <typename A, typename B>
string to_string(pair<A, B> p);

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);

string to_string(const string& s) {
	return '"' + s + '"';
}

string to_string(const char* s) {
	return to_string((string)s);
}

string to_string(bool b) {
	return (b ? "true" : "false");
}

string to_string(vector<bool> v) {
	bool first = true;
	string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(v[i]);
	}
	res += "}\n";
	return res;
}

template <size_t N>
string to_string(bitset<N> v) {
	string res = "";
	for (size_t i = 0; i < N; i++) {
		res += static_cast<char>('0' + v[i]);
	}
	return res;
}

template <typename A>
string to_string(A v) {
	bool first = true;
	string res = "{";
	for (const auto& x : v) {
		if (!first) {
			res += ", ";
		}
		first = false;
		res += to_string(x);
	}
	res += "}\n";
	return res;
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
	return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}

template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}

template <typename A, typename B, typename C, typename D, typename E>
string to_string(tuple<A, B, C, D, E> p) {
	return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + "," + to_string(get<4>(p)) + ")";
}

void debug_out() {
	cerr << endl;
}

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
	cerr << " " << to_string(H);
	debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "\n[" << #__VA_ARGS__ << "]:\n", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

// End of Gennady-Korotkevich's template 

void solve() {
	int n; cin >> n;
	vector<pair<ll, ll>> point(n);
	for(int i=0 ; i<n ; i++) 
		cin >> point[i].ff >> point[i].ss;
	if(n <= 4) {
		cout << "YES\n";
		return;
	}
	vector<bool> vis(n);
	int nxt1 = -1, nxt2 = -1;
	vis[0] = vis[1] = 1;
	int cnt = 2;
	ll vecx = point[0].ff - point[1].ff;
	ll vecy = point[0].ss - point[1].ss;
	for(int i=0 ; i<n ; i++) {
		if(vis[i]) continue;
		ll dx = point[i].ff - point[0].ff;
		ll dy = point[i].ss - point[0].ss;
		if(vecx * dy == vecy * dx) {
			cnt += 1;
			vis[i] = 1;
		}
		else {
			nxt1 = nxt2;
			nxt2 = i;
		}
	}
	if(nxt1==-1 || nxt2 == -1) {
		cout << "YES\n";
		return;
	}
	vecx = point[nxt1].ff - point[nxt2].ff;
	vecy = point[nxt1].ss - point[nxt2].ss;
	vis[nxt1] = vis[nxt2] = 1;
	cnt += 2;
	for(int i=0 ; i<n ; i++) {
		if(vis[i]) continue;
		ll dx = point[i].ff - point[nxt1].ff;
		ll dy = point[i].ss - point[nxt1].ss;
		if(vecx * dy == vecy * dx) {
			cnt += 1;
			vis[i] = 1;
		}
		else {
			;
		}
	}
	if(cnt==n) {
		cout << "YES\n";
		return;
	}
	vis = vector<bool>(n);
	nxt1 = nxt2 = -1;
	cnt = 2;
	vecx = point[2].ff - point[1].ff;
	vecy = point[2].ss - point[1].ss;
	vis[1] = 1, vis[2] = 1;
	for(int i=0 ; i<n ; i++) {
		if(vis[i]) continue;
		ll dx = point[i].ff - point[1].ff;
		ll dy = point[i].ss - point[1].ss;
		if(vecx * dy == vecy * dx) {
			cnt += 1;
			vis[i] = 1;
		}
		else {
			nxt1 = nxt2;
			nxt2 = i;
		}
	}
	if(nxt1==-1 || nxt2 == -1) {
		cout << "YES\n";
		return;
	}
	vecx = point[nxt1].ff - point[nxt2].ff;
	vecy = point[nxt1].ss - point[nxt2].ss;

	vis[nxt1] = vis[nxt2] = 1;
	cnt += 2;
	for(int i=0 ; i<n ; i++) {
		if(vis[i]) continue;
		ll dx = point[i].ff - point[nxt1].ff;
		ll dy = point[i].ss - point[nxt1].ss;
		if(vecx * dy == vecy * dx) {
			cnt += 1;
			vis[i] = 1;
		}
		else {
			;
		}
	}
	if(cnt == n) {
		cout << "YES\n";
		return;
	}
	vis = vector<bool>(n);
	cnt = 2;
	nxt1 = nxt2 = -1;
	vecx = point[2].ff - point[0].ff;
	vecy = point[2].ss - point[0].ss;
	vis[0] = vis[2] = 1;
	for(int i=0 ; i<n ; i++) {
		if(vis[i]) continue;
		ll dx = point[i].ff - point[0].ff;
		ll dy = point[i].ss - point[0].ss;
		if(vecx * dy == vecy * dx) {
			cnt += 1;
			vis[i] = 1;
		}
		else {
			nxt1 = nxt2;
			nxt2 = i;
		}
	}
	if(nxt1==-1 || nxt2 == -1) {
		cout << "YES\n";
		return;
	}
	vecx = point[nxt1].ff - point[nxt2].ff;
	vecy = point[nxt1].ss - point[nxt2].ss;
	vis[nxt1] = vis[nxt2] = 1;
	cnt += 2;
	for(int i=0 ; i<n ; i++) {
		if(vis[i]) continue;
		ll dx = point[i].ff - point[nxt1].ff;
		ll dy = point[i].ss - point[nxt1].ss;
		if(vecx * dy == vecy * dx) {
			cnt += 1;
			vis[i] = 1;
		}
		else {
			;
		}
	}
	if(cnt == n) {
		cout << "YES\n";
		return;
	}
	cout << "NO\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}