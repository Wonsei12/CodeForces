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

using pii = pair<int, int>;
using ll = long long;
const ll MOD = 1e9 + 7;
const long double PI = acos(-1.0);

void solve() {
	int n, m; cin >> n >> m;
	vector<string> s(n);
	for(int i=0 ; i<n ; i++) {
		cin >> s[i];
	}
	auto rvs = [&](int x, int y) {
		s[x][y] = '0' + '1' - s[x][y];
		return;
	};
	vector<pii> ans;
	for(int i=0 ; i<n-2 ; i++) {
		for(int j=0 ; j<m-1 ; j++) {
			if(s[i][j]=='0'&&s[i][j+1]=='0') continue;
			if(s[i][j]=='0'&&s[i][j+1]=='1') {
				ans.push_back({i,j+1}); rvs(i,j+1);
				ans.push_back({i+1,j}); rvs(i+1,j);
				ans.push_back({i+1,j+1}); rvs(i+1,j+1);
			} else if(s[i][j]=='1'&&s[i][j+1]=='0') {
				ans.push_back({i,j}); rvs(i,j);
				ans.push_back({i+1,j}); rvs(i+1,j);
				ans.push_back({i+1,j+1}); rvs(i+1,j+1);
			} else if(s[i][j]=='1'&&s[i][j+1]=='1') {
				ans.push_back({i,j}); rvs(i,j);
				ans.push_back({i,j+1}); rvs(i,j+1);
				ans.push_back({i+1,j}); rvs(i+1,j);
			}
		}
	}
	for(int i=0 ; i<m-1 ; i++) {
		if(s[n-2][i]=='0'&&s[n-1][i]=='0') continue;
		else if(s[n-2][i]=='1'&&s[n-1][i]=='0') {
			ans.push_back({n-2,i}); rvs(n-2,i);
			ans.push_back({n-2,i+1}); rvs(n-2,i+1);
			ans.push_back({n-1,i+1}); rvs(n-1,i+1);
		} else if(s[n-2][i]=='0'&&s[n-1][i]=='1') {
			ans.push_back({n-1,i}); rvs(n-1,i);
			ans.push_back({n-2,i+1}); rvs(n-2,i+1);
			ans.push_back({n-1,i+1}); rvs(n-1,i+1);
		} else if(s[n-2][i]=='1'&&s[n-1][i]=='1') {
			ans.push_back({n-2,i}); rvs(n-2,i); 
			ans.push_back({n-1,i}); rvs(n-1,i);
			ans.push_back({n-1,i+1}); rvs(n-1,i+1);
		} 
	}
	int cnt = 0;
	vector<pii> onbits,offbits;
	for(int i=n-2 ; i<n ; i++) {
		for(int j=m-2 ; j<m ; j++) {
			cnt += (s[i][j] == '1');
			if(s[i][j]=='1') onbits.push_back({i,j});
			else offbits.push_back({i,j});
		}
	}
	if(cnt==0) ;
	else if(cnt==1) {
		ans.push_back(onbits[0]);
		ans.push_back(offbits[0]);
		ans.push_back(offbits[1]);
		ans.push_back(onbits[0]);
		ans.push_back(offbits[1]);
		ans.push_back(offbits[2]);
		ans.push_back(onbits[0]);
		ans.push_back(offbits[0]);
		ans.push_back(offbits[2]);
	} else if(cnt==2) {
		ans.push_back(onbits[0]);
		ans.push_back(offbits[0]);
		ans.push_back(offbits[1]);
		ans.push_back(offbits[0]);
		ans.push_back(offbits[1]);
		ans.push_back(onbits[1]);	
	} else if(cnt==3) {
		ans.push_back(onbits[0]);
		ans.push_back(onbits[1]);
		ans.push_back(onbits[2]);
	} else {
		ans.push_back(onbits[0]);
		ans.push_back(onbits[1]);
		ans.push_back(onbits[2]);
		ans.push_back(onbits[1]);
		ans.push_back(onbits[2]);
		ans.push_back(onbits[3]);
		ans.push_back(onbits[2]);
		ans.push_back(onbits[3]);
		ans.push_back(onbits[0]);
		ans.push_back(onbits[0]);
		ans.push_back(onbits[1]);
		ans.push_back(onbits[3]);
	}
	cout << sz(ans)/3 << "\n";
	for(int i=0 ; i<sz(ans) ; i++) {
		cout << ans[i].ff + 1 << " " << ans[i].ss + 1 << " ";
		if(i%3==2) cout << "\n"; 
	}
	return;
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--)
		solve();
}