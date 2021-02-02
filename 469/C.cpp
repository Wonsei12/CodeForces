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
	int n, m, h; cin >> n >> m >> h;
	vector<int> times(n);
	vector<vector<int>> G(n), rG(n);
	vector<int> deg(n);
	for(int i=0 ; i<n ; i++) {
		cin >> times[i];
	}	
	for(int i=0 ; i<m ; i++) {
		int u, v; cin >> u >> v; u--, v--;
		bool k1 = false, k2 = false;
		if((times[u] + 1) % h == times[v]) {
			G[u].push_back(v);
			rG[v].push_back(u);
			deg[u] += 1;
		} 
		if((times[v] + 1) % h == times[u]) {
			G[v].push_back(u);
			rG[u].push_back(v);
			deg[v] += 1;
		}
	}
	vector<bool> vis(n);
	stack<int> st;
	function<void(int, int)> dfs = [&](int v, int p) {
		vis[v] = 1;
		for(int nxt : G[v]) {
			if(nxt == p || vis[nxt])
				continue;
			dfs(nxt, v);
		}
		st.push(v);
	};	

	for(int i=0 ; i<n ; i++) {
		if(vis[i])
			continue;
		dfs(i,-1);	
	}

	vis = vector<bool>(n);
	vector<int> num(n);
	vector<vector<int>> ans(n);	
	int cnt = 0;

	function<void(int, int)> dfs2 = [&](int v, int p) {
		vis[v] = 1;
		num[v] = cnt;
		ans[cnt].push_back(v);
		for(int nxt : rG[v]) {
			if(nxt == p || vis[nxt])
				continue;
			dfs2(nxt, v);
		}
	};

	for(int i=0 ; i<n ; i++) {
		int cur = st.top(); st.pop();
		if(vis[cur]) 
			continue;
		dfs2(cur, -1);
		cnt ++;
	}
	int mn = INF, mnI = -1;
	for(int i=0 ; i<n ; i++) {
		if(sz(ans[i]) == 0) continue;
		bool groupfail = false;
		for(int x : ans[i]) {
			bool fail = false;
			for(int k : G[x]) {
				if(num[k] == num[x]) continue;
				fail = true; break;
			}
			groupfail |= fail;
		}
		if(!groupfail) {
			if(mn > sz(ans[i])) {
				mn = sz(ans[i]);
				mnI = i;
			}
		}
	}
	cout << mn << "\n";
	for(auto x : ans[mnI]) {
		cout << x+1 << " ";
	}
	return;
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}