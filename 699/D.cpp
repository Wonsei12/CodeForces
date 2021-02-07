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
	int n, m; cin >> n >> m;
	vector<string> G(n);
	for(int i=0 ; i<n ; i++) {
		cin >> G[i];
	}
	if(m%2==1) {
		cout << "YES\n";
		for(int i=0 ; i<m+1 ; i++) {
			cout << (i % 2) + 1 << " ";
		}
		cout << "\n";
		return;
	}
	int x1 = -1, x2 = -1;
	for(int i=0 ; i<n ; i++) {
		for(int j=0 ; j<n ; j++) {
			if(i==j) continue;
			if(G[i][j] == G[j][i]) {
				x1 = i, x2 = j;
				break;
			}
		}
		if(x1 != -1) break;
	}
	if(x1 != -1) {
		cout << "YES\n";
		for(int i=0 ; i<m+1 ; i++) {
			if(i % 2 == 0) {
				cout << x1+1 << " ";
			} else { 
				cout << x2+1 << " ";
			}
		}
		cout << "\n";
		return;
	}
	if(n==2) {
		cout << "NO\n";
		return;
	}
	if(m==2) {
		if(G[0][1] == G[1][2]) {
			cout << "YES\n";
			cout << "1 2 3\n";
			return;
		}
		if(G[0][2] == G[2][1]) {
			cout << "YES\n";
			cout << "1 3 2\n";
			return;
		}
		if(G[1][0] == G[0][2]) {
			cout << "YES\n";
			cout << "2 1 3\n";
			return;
		}
		if(G[1][2] == G[2][0]) {
			cout << "YES\n";
			cout << "2 3 1\n";
			return;
		}
		if(G[2][0] == G[0][1]) {
			cout << "YES\n";
			cout << "3 1 2\n";
			return;
		}
		if(G[2][1] == G[1][0]) {
			cout << "YES\n";
			cout << "3 2 1\n";
			return;
		}
	}
	if(G[0][1] == G[1][2] && G[1][2] == G[2][0]) {
		cout << "YES\n";
		for(int i=0 ; i<m+1 ; i++) {
			cout << i%3 + 1 << " ";
		}
		cout << "\n";
		return;
	}
	if(m % 4 == 0) {
		if(G[0][1] != G[0][2]) {
			cout << "YES\n";
			cout << 1 << " ";
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 2 << " ";
				} else {
					cout << 1 << " ";
				}
			}
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 3 << " ";
				} else {
					cout << 1 << " ";
				}
			}
			cout << "\n";
			return;
		}
		if(G[1][0] != G[1][2]) {
			cout << "YES\n";
			cout << 2 << " ";
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 1 << " ";
				} else {
					cout << 2 << " ";
				}
			}
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 3 << " ";
				} else {
					cout << 2 << " ";
				}
			}
			cout << "\n";
			return;
		}
		if(G[2][0] != G[2][1]) {
			cout << "YES\n";
			cout << 3 << " ";
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 1 << " ";
				} else {
					cout << 3 << " ";
				}
			}
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 2 << " ";
				} else {
					cout << 3 << " ";
				}
			}
			cout << "\n";
			return;
		}
	} else {
		m-= 2;
		if(G[0][1] != G[0][2]) {
			// 중심은 0
			int in = -1, out = -1;
			if(G[1][0] == G[0][2]) in = 1, out = 2;
			if(G[2][0] == G[0][1]) in = 2, out = 1;
			if(in == -1) goto x;
			cout << "YES\n";
			cout << in+1 << " ";
			cout << 1 << " ";
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 2 << " ";
				} else {
					cout << 1 << " ";
				}
			}
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 3 << " ";
				} else {
					cout << 1 << " ";
				}
			}
			cout << out+1 << " ";
			cout << "\n";
			return;
		}x:;
		if(G[1][0] != G[1][2]) {
			int in = -1, out = -1;
			if(G[0][1] == G[1][2]) in = 0, out = 2;
			if(G[2][1] == G[1][0]) in = 2, out = 0;
			if(in == -1) goto y;
			cout << "YES\n";
			cout << in+1 << " ";
			cout << 2 << " ";
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 1 << " ";
				} else {
					cout << 2 << " ";
				}
			}
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 3 << " ";
				} else {
					cout << 2 << " ";
				}
			}
			cout << out+1 << " ";
			cout << "\n";
			return;
		}y:;
		if(G[2][0] != G[2][1]) {
			int in = -1, out = -1;
			if(G[0][2] == G[2][1]) in = 0, out = 1;
			if(G[1][2] == G[2][0]) in = 1, out = 0;
			if(in == -1) assert(false);
			cout << "YES\n";
			cout << in+1 << " ";
			cout << 3 << " ";
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 1 << " ";
				} else {
					cout << 3 << " ";
				}
			}
			for(int i=0 ; i<m/2 ; i++) {
				if(i%2==0) {
					cout << 2 << " ";
				} else {
					cout << 3 << " ";
				}
			}
			cout << out+1 << " ";
			cout << "\n";
			return;
		}
	}
	assert(false);
}	

int main() {
	IOS;
	int t = 1; cin >> t;
	while(t--)
		solve();
}