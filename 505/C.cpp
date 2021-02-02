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
	string s; cin >> s;
	int n = sz(s);
	vector<int> maxwb2(n), maxbw2(n);
	maxwb2[0] = (s[0]=='w');
	maxbw2[0] = (s[0]=='b');
	for(int i=1 ; i<sz(s) ; i++) {
		if(i%2) {
			maxwb2[i] = (s[i] == 'b') ? (maxwb2[i-1] + 1) : 0;
			maxbw2[i] = (s[i] == 'w') ? (maxbw2[i-1] + 1) : 0;
		} else {
			maxwb2[i] = (s[i] == 'w') ? (maxwb2[i-1] + 1) : 0;
			maxbw2[i] = (s[i] == 'b') ? (maxbw2[i-1] + 1) : 0;
		}
	}
	reverse(all(s));
	vector<int> maxwb(n), maxbw(n);
	maxwb[0] = (s[0]=='w');
	maxbw[0] = (s[0]=='b');
	for(int i=1 ; i<sz(s) ; i++) {
		if(i%2) {
			maxwb[i] = (s[i] == 'b') ? (maxwb[i-1] + 1) : 0;
			maxbw[i] = (s[i] == 'w') ? (maxbw[i-1] + 1) : 0;
		} else {
			maxwb[i] = (s[i] == 'w') ? (maxwb[i-1] + 1) : 0;
			maxbw[i] = (s[i] == 'b') ? (maxbw[i-1] + 1) : 0;
		}
	}
	reverse(all(maxwb));
	reverse(all(maxbw));
	int mx = 0; 
	for(int i=0 ; i<n ; i++) {
		mx = max(mx, maxbw2[i]);
		mx = max(mx, maxwb2[i]);
	}
	reverse(all(s));
	int mxz = 0, mxy = 0;
	if(s[0]=='b') {
		for(int i=0 ; i<n ; i++) {
			mxz = max(mxz, maxbw2[i]);
			if(maxbw2[i] == 0) break;
		}
	} else {
		for(int i=0 ; i<n ; i++) {
			mxz = max(mxz, maxwb2[i]);
			if(maxwb2[i] == 0) break;
		}
	}
	if(s[n-1]=='w') {
		for(int i=n-1 ; i>=0 ; i--) {
			mxy = max(mxy, maxwb[i]);
			if(maxwb[i] == 0) break;
		}
	} 
	else {
		for(int i=n-1 ; i>=0 ; i--) {
			mxy = max(mxy, maxbw[i]);
			if(maxbw[i] == 0) break;
		}
	} 
	int z = mxz + mxy; if(z >= n) z = n;
	if(s[0]==s[n-1]) z=0;
	mx = max(mx, z);
	cout << mx << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}