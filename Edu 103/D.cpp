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

vector<int> par0(300300), par1(300300);
vector<int> deg0(300300), deg1(300300);

int find(int x) {
	if(par0[x]==x) return x;
	return par0[x] = find(par0[x]);
}

void union_par(int u, int v) {
	u = find(u);
	v = find(v);
	if(u==v) return;
	if(u>v)swap(u,v);
	deg0[u] += deg0[v];
	par0[v] = u;
}


int find2(int x) {
	if(par1[x]==x) return x;
	return par1[x] = find2(par1[x]);
}

void union_par2(int u, int v) {
	u = find2(u);
	v = find2(v);
	if(u==v) return;
	if(u>v)swap(u,v);
	deg1[u] += deg1[v];
	par1[v] = u;
}

void solve() {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> a(n);
	for(int i=0 ; i<n ; i++) {
		if(s[i]=='R' && i%2==0 || s[i]=='L' && i%2 == 1)
			a[i] = 1;
		else
			a[i] = 0;
	}
	for(int i=0 ; i<n+1 ; i++)
		par0[i] = i, deg0[i] = 1, par1[i]=i,deg1[i]=1;
	for(int i=0 ; i<n+1 ; i++) {
		if(i==0) {
			if(a[i]==0) union_par(0,1);
			else union_par2(0,1);
		}
		else if(i==n) {
			if(a[n-1]==0) union_par(n-1, n);
			else union_par2(n-1,n);
		}
		else {
			if(a[i-1]==0) {
				union_par(i-1,i);
			} else {
				union_par2(i-1,i);
			} 
			if(a[i]==0) {
				union_par(i,i+1);
			} else {
				union_par2(i,i+1);
			}
		}
	}
	for(int i=0 ; i<n+1 ; i++) {
		if(i==0) {
			if(s[0]=='L') {
				cout << 1 << " ";
			} else {
				if(a[0]==0) {
					int x = find(0);
					cout << deg0[x] << " ";
				} else {
					int x = find2(0);
					cout << deg1[x] << " ";
				}
			}
		} else if(i==n) {
			if(s[n-1]=='L') {
				if(a[n-1]==0) {
					int x = find(n-1);
					cout << deg0[x] << " ";
				} else {
					int x = find2(n-1);
					cout << deg1[x] << " ";
				}
			} else {
				cout << 1 << " ";
			}
		} else {
			if(s[i-1]=='R'&&s[i]=='L') {
				cout << 1 << " ";
			} else if(s[i-1]=='L'&&s[i]=='R') {
				if(a[i-1]==0) {
					int x = find(i-1);
					cout << deg0[x] << " ";
				} else {
					int x = find2(i-1);
					cout << deg1[x] << " ";
				}
			} else if(s[i-1]=='L') {
				if(a[i-1]==0) {
					int x = find(i-1);
					cout << deg0[x] << " ";
				} else {
					int x = find2(i-1);
					cout << deg1[x] << " ";
				}
			} else {
				if(a[i]==0) {
					int x = find(i);
					cout << deg0[x] << " ";
				} else {
					int x = find2(i);
					cout << deg1[x] << " ";
				}
			}
		}
	}
	cout << "\n";
}

int main() {
	IOS;
	int t = 1; cin >> t;
	while(t--)
		solve();
}