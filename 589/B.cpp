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

// Copied from Gennady-Korotkevich's template

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
	int h, w; cin >> h >> w;
	vector<vector<int>> G(h+1, vector<int>(w+1));
	vector<int> hs(h),ws(w);
	for(int i=0 ; i<h ; i++) {
		cin >> hs[i];
	}
	for(int i=0 ; i<w ; i++) {
		cin >> ws[i];
	}
	for(int i=0 ; i<h ; i++) {
		for(int j=0 ; j<hs[i] ; j++) {
			G[i][j] = 1;
		}
	}
	for(int i=0 ; i<w ; i++) {
		for(int j=0 ; j<ws[i] ; j++) {
			G[j][i] = 1;
		}
	}
	for(int i=0 ; i<h ; i++) {
		if(G[i][hs[i]]==1) {
			cout << 0 << "\n";
			return;
		} else G[i][hs[i]] = 2;
	}
	for(int i=0 ; i<w ; i++) {
		if(G[ws[i]][i]==1) {
			cout << 0 << "\n";
			return;
		} else G[ws[i]][i] = 2;
	}
	ll ans = 1;
	for(int i=0 ; i<h ; i++) {
		for(int j=0 ; j<w ; j++) {
			if(G[i][j] == 0) {
				ans *= 2;
				ans %= MOD;
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}