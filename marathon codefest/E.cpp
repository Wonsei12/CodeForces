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
	int n, m, k; cin >> n >> m >> k;
	vector<pii> edge(m);
	vector<int> deg(n);
	vector<set<int>> G(n);
	for(int i=0 ; i<m ; i++) {
		cin >> edge[i].ff >> edge[i].ss;
		edge[i].ff--; edge[i].ss--;
		deg[edge[i].ff] += 1;
		deg[edge[i].ss] += 1;
		G[edge[i].ff].insert(edge[i].ss);
		G[edge[i].ss].insert(edge[i].ff);
	}
	vector<bool> fuck(n);
	int tot = n;
	queue<int> q;
	for(int i=0 ; i<n ; i++) {
		if(deg[i] < k) {
			q.push(i);
			fuck[i] = true;
			tot-=1;
		}
	}
	set<pii> fucked;
	vector<int> ans;
	for(int i=m-1 ; i>=0 ; i--) {
		while(!q.empty())  {
			int cur = q.front(); q.pop();
			for(int nxt : G[cur]) {
				if(fucked.count({cur,nxt})) continue;
				deg[nxt]--;
				if(deg[nxt] < k && !fuck[nxt]) {
					fuck[nxt] = true;
					q.push(nxt);
					tot-=1;
				}
			}
		}
		ans.push_back(tot);
		int fi=edge[i].ff, se=edge[i].ss;
		if(!fuck[fi]&&!fuck[se]) {
			deg[fi]-=1;
			deg[se]-=1;
			if(deg[fi] < k) {
				fuck[fi] = true;
				q.push(fi);
				tot-=1;
			}
			if(deg[se] < k) {
				fuck[se] = true;
				q.push(se);
				tot-=1;
			} 
		}
		fucked.insert({fi,se});
		fucked.insert({se,fi});
	}
	reverse(all(ans));
	for(auto x : ans)
		cout << x << " ";
}

int main() {
	IOS;
	int t = 1;
	while(t--)
		solve();
}