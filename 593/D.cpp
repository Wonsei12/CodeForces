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
	int n,m,k; cin >> n >> m >> k;
 	vector<int> dx = {0,1,0,-1};
 	vector<int> dy = {1,0,-1,0};
 	int R = 0, D = 1, L = 2, U = 3;
	vector<vector<int>> horObs(n+1);
	vector<vector<int>> verObs(n+1);
	for(int i=1 ; i<=n ; i++) {
		horObs[i].push_back(n+1);
		horObs[i].push_back(0);
		verObs[i].push_back(n+1);
		verObs[i].push_back(0);
	}
	for(int i=0 ; i<k ; i++) {
		int x, y; cin >> x >> y;
		horObs[x].push_back(y);
		verObs[y].push_back(x);
	}
	for(int i=1 ; i<=n ; i++) {
		sort(all(horObs[i]));
		sort(all(verObs[i]));
	}
	int curX = 1, curY = 1, dir = 0;
	int minX = 1, maxX = n, minY = 1, maxY = m;
	ll stepped = 1;
	bool rotate;
	while(1) {
		if(dir == 0) {
			int idx = lower_bound(horObs[curX].begin(),horObs[curX].end(),curY+1)-horObs[curX].begin();
			if(!rotate && min(horObs[curX][idx],maxY) <= curY + 1) {
				rotate = true;
				dir += 1;
				dir %= 4;
			} else if(rotate && min(horObs[curX][idx],maxY) == curY + 1) {
				break;
			}
			else {
				ll z = horObs[curX][idx] - curY - 1;
				z = min(z, (ll)maxY - curY);
				stepped += z;
				rotate = false;
				curY += z;
				maxY = curY;
			}
		} else if(dir == 1) {
			int idx = lower_bound(verObs[curY].begin(),verObs[curY].end(),curX+1)-verObs[curY].begin();
			if(!rotate && min(verObs[curY][idx],maxX) <= curX + 1) {
				rotate = true;
				dir += 1;
				dir %= 4;
			} else if(rotate && min(verObs[curY][idx],maxX) == curX + 1) {
				break;
			}
			else {
				ll z = verObs[curY][idx] - curX - 1;
				z = min(z, (ll)maxX - curX);
				stepped += z;
				rotate = false;
				curX += z;
				maxX = curX;
			}
		} else if(dir == 2) {
			int idx = lower_bound(horObs[curX].begin(),horObs[curX].end(),curY)-horObs[curX].begin()-1;
			if(!rotate && max(horObs[curX][idx],minY) >= curY - 1) {
				rotate = true;
				dir += 1;
				dir %= 4;
			} else if(rotate && max(horObs[curX][idx],minY) == curY - 1) {
				break;
			}
			else {
				ll z =  curY - horObs[curX][idx] - 1;
				z = min(z, (ll)curY - minY);
				stepped += z;
				rotate = false;
				curY -= z;
				minY = curY;
			}
		} else {
			int idx = lower_bound(verObs[curY].begin(),verObs[curY].end(),curX)-verObs[curY].begin()-1;
			if(!rotate && max(verObs[curY][idx],minX) >= curX - 1) {
				rotate = true;
				dir += 1;
				dir %= 4;
			} else if(rotate && max(verObs[curY][idx],minX) == curX - 1) {
				break;
			}
			else {
				ll z = curX - verObs[curY][idx] - 1;
				z = min(z, (ll)curX - minX);
				stepped += z;
				rotate = false;
				curX -= z;
				minX = curX;
			}
		}
	}
	if((ll)stepped + k == (ll)n * m) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}