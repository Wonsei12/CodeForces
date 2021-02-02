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
	ll n, k; cin >> n >> k;
	if(k==1) {
		cout << "YES\n";
		cout << n << "\n";
		return;
	}
	if(n < k * (k+1) / 2) {
		cout << "NO\n";
		return;
	}
	auto can = [&](ll x) {
		ll sum = 0;
		for(int i=0 ; i<k ; i++) {
			sum += x;
			if(sum >= n) {
				return true;
			}
			x *= 2;
		}
		return false;
	};
	ll l=1, r=1e9;
	ll s=0;
	while(l<=r) {
		ll mid = (l+r) / 2;
		if(can(mid)) {
			r = mid - 1;
			s = mid;
		} else {
			l = mid + 1;
		}
	}
	if(k*(s+s+k-1)/2>n) {
		cout << "NO\n";
		return;
	}
	vector<ll> ans(k);
	for(int i=0 ; i<k ; i++) {
		ans[i] = i+1;
		n -= i+1;
	}
	n -= k * (s-1);
	cout << "YES\n";
	vector<ll> pref(k);
	pref[0] = s - 1;
	ll added = s - 1;
	for(int i=1 ; i<k ; i++) {
		ll up = min((ans[i-1]+added)*2-(ans[i]+added), n/(k-i));
		added += up;
		pref[i] = up;
		n -= up * (k-i);
	}
	for(int i=1 ; i<k ; i++) {
		pref[i] += pref[i-1];
	}
	for(int i=0 ; i<k ; i++) {
		cout << ans[i] + pref[i] << " ";
	}
	cout << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}