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
	vector<int> a(n);
	vector<int> cnt(200200);
	for(int i=0 ; i<n ; i++) { 
		cin >> a[i];
		a[i]--;
		cnt[a[i]]+=1;
	}
	vector<int> dan;
	dan.push_back(0);
	for(int i=1 ; i<n-1 ; i++) {
		if(cnt[i]<=1) dan.push_back(i);

	}
	dan.push_back(n-1);
	int mx = 0, mxL, mxR;
	for(int i=0 ; i<200199 ; i++) {
		if(cnt[i]>=1&&mx<cnt[i]) {
			mx=cnt[i];
			mxL=i,mxR=i;
		}
	}
	for(int i=0 ; i<200199 ; i++) {
		if(cnt[i]>=1&&cnt[i+1]>=1&&mx<cnt[i]+cnt[i+1]) {
			mx=cnt[i]+cnt[i+1];
			mxL=i,mxR=i+1;
		}
	}
	for(int i=0 ; i<sz(dan)-1 ; i++) {
		int sum = 0;
		int isZero = (cnt[dan[i]] == 0);
		int isZero2 = (cnt[dan[i+1]]==0);
		for(int j=dan[i]+isZero ; j<=dan[i+1]-isZero2 ; j++) {
			sum += cnt[j];
		}
		if(sum > mx) {
			mx = sum;
			mxL = dan[i];
			mxR = dan[i+1];
		}
	}
	vector<int> rr;
	for(int i=mxL+(cnt[mxL]==0) ; i<=mxR-(cnt[mxR]==0) ; i++) {
		for(int j=0 ; j<cnt[i]-1 ; j++) {
			rr.push_back(i+1);
		}
	}
	for(int i=mxR-(cnt[mxR]==0) ; i>=mxL+(cnt[mxL]==0) ; i--) {
		rr.push_back(i+1);
	}
	cout << sz(rr) << "\n";
	for(auto x : rr) {
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
	IOS;
	int t = 1; 
	while(t--)
		solve();
}